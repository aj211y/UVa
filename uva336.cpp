#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#define M 100000
using namespace std;

map<int,int> dic;
int list[35][35],point[35],node=1,c;
void bfs(int begin,int TTL)
{
	queue<int> wait;
	int ans[35],cur,i;
	for(i=0;i<35;i++)
		ans[i]=M;
	ans[begin]=0;
	wait.push(begin);
	while(!wait.empty())
	{
		cur=wait.front();
		wait.pop();
		for(i=1;i<node;i++)
		{
			if(list[cur][i]==1 && ans[cur]+1<ans[i])
			{
				ans[i]=ans[cur]+1;
				wait.push(i);
			}
		}
	}
	c=0;
	for(i=1;i<node;i++)
	{
		//printf("%d\n",ans[i]);
		if(ans[i]>TTL)
			c++;
	}
}
int main()
{
	int NC,i,id,a,b,j,Case=1;
	
	while(scanf("%d",&NC)!=EOF)
	{
		if(NC==0)
			break;
		dic.clear();
		node=1;
		memset(list,0,sizeof(list));
		memset(point,0,sizeof(point));
		for(i=0;i<NC;i++)
		{
			scanf("%d%d",&a,&b);
			//建圖
			if(dic.find(a)==dic.end())//new node
			{
				dic[a]=node;
				point[node++]=a;
			}
			if(dic.find(b)==dic.end())//new node
			{
				dic[b]=node;
				point[node++]=b;
			}
			list[dic[a]][dic[b]]=1;
			list[dic[b]][dic[a]]=1;
		}//建圖結束
		while(scanf("%d%d",&a,&b))
		{
			if(a==0 && b==0)
				break;
			bfs(dic[a],b);
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",Case++,c,a,b);
		}
		/*for(i=1;i<node;i++)
		{
			printf("id= %d\n",point[i]);
			for(j=0;j<node;j++)
			{
				if(list[i][j]==1)
					printf("%d ",point[j]);
			}
			printf("\n");
		}*/
	}
	return 0;
}
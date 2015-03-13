//WA Ê¨
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

vector<int> list[1000005],ans;
int n,degree[1000005];
void BFS()
{
	int i,tmp,id;
	queue<int> wait;
	for(i=1;i<=n;i++)
	{
		if(degree[i]==0)
			wait.push(i);
	}
	while(!wait.empty())
	{
		tmp=wait.front();
		ans.push_back(tmp);
		wait.pop();
		for(i=0;i<list[tmp].size();i++)
		{
			id=list[tmp][i];
			degree[id]--;
			if(degree[id]==0)
				wait.push(id);
		}
	}
	if(ans.size()<n)
		printf("IMPOSSIBLE\n");
	else
	{
		for(i=0;i<ans.size();i++)
			printf("%d\n",ans[i]);
	}
}
int main()
{
	int m,a,b,i;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0 && m==0)
			break;
		memset(degree,0,sizeof(degree));
		
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			list[a].push_back(b);
			degree[b]++;
		}
		BFS();
		ans.clear();
		for(i=1;i<=n;i++)
			list[i].clear();
	}
	return 0;
}
/*TLE
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
#define Max 19995
using namespace std;

queue<int> wait;
int n,list[Max][Max],degree[Max],ans[Max],now;
bool visited[Max];
void BFS(int id)
{
	int tmp,i;
	wait.push(id);
	while(!wait.empty())
	{
		tmp=wait.front();
		wait.pop();
		visited[tmp]=true;
		ans[now++]=tmp;
		for(i=1;i<=n;i++)
		{
			if(list[tmp][i]==1 && !visited[i])
			{
				degree[i]--;
				if(degree[i]==0)
					wait.push(i);
			}
		}
	}
}
int main()
{
	int m,i,a,b;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0 && m==0)
			break;
		memset(list,0,sizeof(list));
		memset(ans,0,sizeof(ans));
		memset(degree,0,sizeof(degree));
		memset(visited,false,sizeof(visited));
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			list[a][b]=1;
			degree[b]++;
		}
		now=1;
		for(i=1;i<=n;i++)
		{
			if(degree[i]==0&&!visited[i])
				BFS(i);
		}
		if(now<n+1)//¦³Àô
			printf("IMPOSSIBLE\n");
		else
		{
			for(i=1;i<now;i++)
				printf("%d\n",ans[i]);
		}
	}
	return 0;
}*/
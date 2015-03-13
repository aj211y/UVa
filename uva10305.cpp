#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

int list[120][120];
int deg[120],n,m;
void BFS()
{
	int i,tmp;
	queue<int> Q;
	bool flag=false;
	
	for(i=1;i<=n;i++)
	{
		if(deg[i]==0)
			Q.push(i);
	}
	
	while(!Q.empty())
	{
		if(flag)
			printf(" ");
		flag=true;
		printf("%d",Q.front());
		tmp=Q.front();
		Q.pop();
		for(i=1;i<=n;i++)
		{
			if(list[tmp][i]==1)
			{
				deg[i]--;
				if(deg[i]==0)
					Q.push(i);
			}
		}
	}
	printf("\n");
}
int main()
{
	int a,b;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(list,0,sizeof(list));
		memset(deg,0,sizeof(deg));
		if(n==0 && m==0)
			break;
		while(m--)
		{
			scanf("%d%d",&a,&b);
			list[a][b]=1;
			deg[b]++;
		}
		BFS();
	}
	return 0;
}
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int llink[1010],rlink[1010];
bool used[1010];
vector<int> list[1010],Right[25];

bool DFS(int now)
{
	int i,next;
	for(i=0;i<list[now].size();i++)
	{
		next=list[now][i];
		if(!used[next])
		{
			used[next]=true;
			if(!rlink[next] || DFS(rlink[next]))
			{
				llink[now]=next;
				rlink[next]=now;
				return true;
			}
		}
	}
	return false;
}
int bipartite(int L)
{
	memset(llink,0,sizeof(llink));
	memset(rlink,0,sizeof(rlink));
	int i,ret=0;
	for(i=1;i<=L;i++)
	{
		memset(used,false,sizeof(used));
		if(DFS(i))
			ret++;
	}
	return ret;
}
int main()
{
	int n,k,i,rid,num,m,j,ans,job;
	bool space;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		if(n==0 && k==0)
			break;
		for(i=0;i<1010;i++)
			list[i].clear();
		for(i=0;i<25;i++)
			Right[i].clear();
		rid=1;
		job=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&num);
			job+=num;
			while(num--)
				Right[i].push_back(rid++);
		}
		for(i=1;i<=k;i++)
		{
			scanf("%d",&num);
			while(num--)
			{
				scanf("%d",&m);
				for(j=0;j<Right[m].size();j++)
					list[i].push_back(Right[m][j]);
			}
		}
		ans=bipartite(k);
		if(ans==job)
		{
			printf("1\n");
			for(i=1;i<=n;i++)
			{
				space=false;
				for(j=0;j<Right[i].size();j++)
				{
					if(space)	
						printf(" ");
					space=true;
					printf("%d",rlink[Right[i][j]]);
				}
				printf("\n");
			}
		}
		else
			printf("0\n");
	}
	return 0;
}
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int llink[110],rlink[110],l[110],r[110];
bool used[110];
vector<int> list[110];

bool DFS(int now)
{
	int next,i;
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
		memset(used,0,sizeof(used));
		if(DFS(i))
			ret++;
	}
	return ret;
}
int main()
{
	int t,test,n,m,i,j,ans;
	scanf("%d",&test);
	for(t=1;t<=test;t++)
	{
		memset(l,0,sizeof(l));
		memset(r,0,sizeof(r));
		for(i=0;i<110;i++)
			list[i].clear();
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",&l[i]);
		scanf("%d",&m);
		for(i=1;i<=m;i++)
			scanf("%d",&r[i]);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(r[j]>=l[i] && l[i]!=0 && r[j]%l[i]==0 || r[j]==0)//注意~~~l[i]為0時會有runtime error
					list[i].push_back(j);
			}
		}
		ans=bipartite(n);
		printf("Case %d: %d\n",t,ans);
	}
	return 0;
}
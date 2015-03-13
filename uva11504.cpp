#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<stack>
#include<algorithm>
#define Max 100010
using namespace std;

vector<int> list[Max],SCC[Max];
stack<int> wait;
int dfn[Max],low[Max],dfn_count,scc_cnt,scc_no[Max],ans,fa[Max];
bool inS[Max],vis[Max];

void tarjan(int now)
{
	int i,next;
	dfn[now]=low[now]=dfn_count++;
	wait.push(now);
	inS[now]=true;
	for(i=0;i<list[now].size();i++)
	{
		next=list[now][i];
		if(!dfn[next])//not visited
		{
			tarjan(next);
			low[now]=min(low[now],low[next]);
		}
		else if(inS[next])//next in wait
			low[now]=min(low[now],dfn[next]);
	}
	if(dfn[now]==low[now])
	{
		do{
			next=wait.top();
			//printf("now-%d next-%d\n",now,next);
			inS[next]=false;
			scc_no[next]=scc_cnt;
			//printf("scc_no[%d]=%d\n",next,scc_cnt);
			wait.pop();
		}while(now!=next);
		scc_cnt++;
	}
}
void dfs(int now)
{
	int i,next;
	for(i=0;i<list[now].size();i++)
	{
		next=list[now][i];
		if(!vis[next])
		{
			vis[next]=true;
			dfs(next);
		}
	}
}
int main()
{
	int t,m,n,a,b,i,j,next;
	scanf("%d",&t);
	while(t--)
	{
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		memset(inS,false,sizeof(inS));
		memset(scc_no,0,sizeof(scc_no));
		for(i=0;i<Max;i++)
		{
			list[i].clear();
			SCC[i].clear();
		}
		while(!wait.empty())
			wait.pop();
		scanf("%d%d",&n,&m);
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			list[a].push_back(b);
		}
		dfn_count=1;
		scc_cnt=1;
		for(i=1;i<=n;i++)
		{
			if(!dfn[i])
				tarjan(i);
		}
		memset(fa,0,sizeof(fa));
		for(i=1;i<=n;i++)  
        {  
            for(j=0;j<list[i].size();j++)  
            {  
                next=list[i][j];  
                if(scc_no[i]!=scc_no[next])  
                {  
                    SCC[scc_no[i]].push_back(scc_no[next]);  
                    fa[scc_no[next]]++;  
                }  
            }  
        }  
        memset(vis,false,sizeof(vis));  
        ans=0;  
        for(i=1;i<scc_cnt;i++)  
        {  
            if(!fa[i])  
            {  
                vis[i]=true; 
				//printf("%d\n",i);
                dfs(i);  
                ans++;  
            }  
        }  
		printf("%d\n",ans);
	}
	return 0;
}
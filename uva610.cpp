//cut edge
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#define Max 1005
using namespace std;


vector<int> list[Max];
int dfn[Max],low[Max],dfn_count;
bool bri[Max][Max],vertex[Max],edge[Max][Max];
void DFN(int now,int pa)
{
	int i,next;
	dfn[now]=low[now]=dfn_count++;
	//printf("dfn-%d\n",dfn[now]);
	for(i=0;i<list[now].size();i++)
	{
		next=list[now][i];
		//printf("next-%d\n",next);
		if(!dfn[next])
		{
			
			DFN(next,now);
			low[now]=min(low[now],low[next]);
			//printf("dfn-%d low-%d\n",dfn[now],low[now]);
			if(dfn[now]<low[next])//cut edge
			{
				//printf("cut\n");
				bri[now][next]=bri[next][now]=true;
			}
		}
		else if(low[now] > low[next] && next!=pa)
		{
			low[now]=min(low[now],dfn[next]);
			///printf("dfn-%d low-%d\n",dfn[now],low[now]);
			
		}
	}
}
void print(int now)
{
	int i,next;
	vertex[now]=true;
	for(i=0;i<list[now].size();i++)
	{
		next=list[now][i];
		if(!(edge[now][next]||bri[now][next]))
		{
			printf("%d %d\n",now,next);
			edge[now][next]=true;
			edge[next][now]=true;
			print(next);
		}
	}
}
int main()
{
	int n,m,a,b,i,test=1;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0)
			break;
		for(i=0;i<Max;i++)
		{
			list[i].clear();
		}
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		memset(bri,false,sizeof(bri));
		memset(vertex,false,sizeof(vertex));
		memset(edge,false,sizeof(edge));
		
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			list[a].push_back(b);
			list[b].push_back(a);
		}
		dfn_count=1;
		DFN(1,0);
		printf("%d\n\n",test++);
		for(i=1;i<=n;i++)
		{
			if(!vertex[i])
				print(i);
		}
		for(a=1;a<=n;a++)
		{
			for(b=1;b<=n;b++)
			{
				if(bri[a][b])
					printf("%d %d\n",a,b);
			}
		}
		printf("#\n");
	}
	return 0;
}
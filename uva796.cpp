#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#define Max 1010
using namespace std;
struct node
{
	int s,d;
};

vector<int> list[Max];
vector<node> ans;
int dfn[Max],low[Max],dfn_count;
void DFN(int now,int pa)
{
	int i,next;
	node n;
	dfn[now]=low[now]=dfn_count++;
	//printf("dfn-%d\n",dfn[now]);
	for(i=0;i<list[now].size();i++)
	{
		next=list[now][i];
		//printf("next-%d\n",next);
		if(dfn[next]<0)
		{
			DFN(next,now);
			low[now]=min(low[now],low[next]);
			//printf("dfn-%d low-%d\n",dfn[now],low[now]);
			if(low[next]>dfn[now])
			{
				//printf("cut\n");
				n.s=min(now,next);
				n.d=max(now,next);
				ans.push_back(n);
			}
		}
		else if(low[next]<low[now] && next!=pa)
		{	
			low[now]=min(low[now],dfn[next]);
			//printf("dfn-%d low-%d\n",dfn[now],low[now]);
		}
	}
}
bool cmp(node a,node b)
{
	if(a.s<b.s)
		return true;
	else if(a.s==b.s && a.d<b.d)
		return true;
	else
		return false;
}
int main()
{
	int n,i,a,b,num;
	while(scanf("%d",&n)!=EOF)
	{
		memset(list,0,sizeof(list));
		memset(dfn,-1,sizeof(dfn));
		memset(low,-1,sizeof(low));
		ans.clear();
		for(i=0;i<n;i++)
		{
			scanf("%d (%d)",&a,&num);
			while(num--)
			{
				scanf("%d",&b);
				list[a].push_back(b);
				list[b].push_back(a);
			}
		}
		dfn_count=1;
		for(i=0;i<n;i++)
		{
			if(dfn[i]<0)//還沒走過
				DFN(i,-1);
		}
		sort(ans.begin(),ans.end(),cmp);
		printf("%d critical links\n",ans.size());
		for(i=0;i<ans.size();i++)
		{
			printf("%d - %d\n",ans[i].s,ans[i].d);
		}
		printf("\n");
	}
	
	return 0;
}
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define Max 40
#define INF 1000000
using namespace std;

int cap[Max][Max],v[Max],flow[Max][Max],p[Max];
bool DFS(int cur,int t)
{
	int i,j,k;
	v[cur]=1;
	if(cur==t)
		return true;
	for(i=0;i<=t;i++)
	{
		if(v[i]) continue;
		if(cap[cur][i]-flow[cur][i]>0 || flow[i][cur]>0)
		{
			p[i]=cur;
			if(DFS(i,t))return true;
		}
	}
	return false;
}
int FindFlow(int s,int t)
{
	int i,j,k,pre;
	int f=INF;
	//找bottle neck
	for(i=t;i!=s;i=pre)
	{
		pre=p[i];
		if(cap[pre][i]-flow[pre][i]>0)
			f=min(f,cap[pre][i]-flow[pre][i]);
		else
			f=min(f,flow[i][pre]);
	}
	//更新圖
	for(i=t;i!=s;i=pre)
	{
		pre=p[i];
		if(cap[pre][i]-flow[pre][i]>0)
			flow[pre][i]+=f;
		else
			flow[i][pre]-=f;
	}
	return f;
}
int FordFulkerson(int s,int t)
{
	int i,j,k;
	int ret=0;
	memset(flow,0,sizeof(flow));
	while(1)
	{
		memset(v,0,sizeof(v));//visited
		if(!DFS(s,t))
			break;
		ret+=FindFlow(s,t);
	}
	return ret;
}
int main()
{
	int T,i,n,m,j,num,k,item,ans;
	bool posess[30];//有沒有擁有這種物品了
	scanf("%d",&T);//幾個test cases
	for(i=1;i<=T;i++)
	{
		scanf("%d%d",&n,&m);//n個人m種物品
		memset(cap,0,sizeof(cap));
		memset(posess,false,sizeof(posess));
		scanf("%d",&num);
		for(k=0;k<num;k++)
		{
			scanf("%d",&item);
			cap[0][item]++;
		}
		for(k=1;k<=m;k++)//T點 看Bob最後擁有幾種物品
			cap[k][n+m]=1;
		for(j=1;j<n;j++)//Bob朋友有的東西--建圖
		{
			memset(posess,false,sizeof(posess));
			scanf("%d",&num);
			for(k=0;k<num;k++)
			{
				scanf("%d",&item);
				if(!posess[item])
					posess[item]=true;
				else
					cap[m+j][item]++;//第j個朋友有多餘的item可以拿出來交換
			}
			for(k=1;k<=m;k++)//1~m是物品的點
			{
				if(!posess[k])//第j個朋友沒有這個東西
					cap[k][m+j]=1;
			}
		}//建圖完畢
		ans=FordFulkerson(0,n+m);
		printf("Case #%d: %d\n",i,ans);
	}
	return 0;
}
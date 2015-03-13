#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define Max 1100
using namespace std;

struct elephant
{
	int id,W,IQ;
}list[Max];
int dp[Max],id,p[Max];
bool cmp(elephant a,elephant b)
{
	if(a.W>b.W)
		return true;
	else if(a.W==b.W && a.IQ<b.IQ)
		return true;
	else
		return false;
}
void LIS()
{
	int i,j,M,Mp;
	memset(p,-1,sizeof(p));//parent
	dp[0]=1; M=1; Mp=0;
	for(i=1;i<id;i++)
	{
		for(j=0;j<i;j++)
		{
			if(list[i].W < list[j].W && list[i].IQ > list[j].IQ && dp[j]+1>dp[i])
			{
				dp[i]=dp[j]+1;
				p[i]=j;
				if(dp[i]>M)
				{
					M=dp[i];
					Mp=i;
				}
			}
		}
	}
	printf("%d\n",M);
	for(i=Mp;i>=0;i=p[i])
		printf("%d\n",list[i].id);
}
int main()
{
	elephant E;
	id=0;
	while(scanf("%d%d",&E.W,&E.IQ)!=EOF)
	{
		E.id=id+1;
		dp[id]=1;
		list[id++]=E;
	}
	sort(list,list+id,cmp);
	LIS();
	return 0;
}
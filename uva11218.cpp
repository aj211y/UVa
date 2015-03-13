#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

struct node
{
	int a,b,c,cost;
}list[100];
int dp[550],n;
void sol(int now,int pos)
{
	int tmp_pos,i;
	tmp_pos=pos|(1<<(list[now].a-1))|(1<<(list[now].b-1))|(1<<(list[now].c-1));//哪三個位置
	//printf("now%d pos%d tmp_pos%d\n",now,pos,tmp_pos);
	if(dp[tmp_pos]<=dp[pos]+list[now].cost)
	{
		dp[tmp_pos]=dp[pos]+list[now].cost;
		pos=tmp_pos;
		//printf("dp[%d]=%d\n",pos,dp[pos]);
		for(i=now+1;i<=n;i++)
		{
			tmp_pos=(1<<(list[i].a-1))|(1<<(list[i].b-1))|(1<<(list[i].c-1));//哪三個位置
			//printf("%d pos%d\n",pos&tmp_pos,pos);
			if((pos&tmp_pos)==0)//表示沒有重複的地方
			{
				//printf("%d\n",i);
				sol(i,pos);
			}
		}
	}	
}
int main()
{
	int test=1,i;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;i++)
			scanf("%d%d%d%d",&list[i].a,&list[i].b,&list[i].c,&list[i].cost);
		for(i=1;i<=n;i++)
			sol(i,0);
		if(dp[511]!=0)
			printf("Case %d: %d\n",test++,dp[511]);
		else
			printf("Case %d: -1\n",test++);
	}
	return 0;
}
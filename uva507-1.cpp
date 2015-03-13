/*
猔種肈ヘ璶―妓程 跋丁琿i~j癬﹍翴i璶禫禫
代戈
	3
	4 
	  6 -7 6    *1~2程ㄎ
	5 
	  9 -9 -9 9 *1~2程ㄎ
	5
	  9 -9 9 -9 *1~4程ㄎ
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define Max 20010
using namespace std;

int list[Max],dp[Max],r,s[Max];
void MSS(int x)
{
	int start,i,M,Mp,len;
	dp[1]=list[1];
	M=list[1];
	s[1]=1;
	Mp=1;
	start=1;
	for(i=2;i<r;i++)
	{
		if(list[i]+dp[i-1] < 0 || list[i]+dp[i-1] <list[i])
		{
			start=i;
			dp[i]=list[i];
		}
		else
		{
			dp[i]=list[i]+dp[i-1];
		}
		s[i]=start;
		if(M<=dp[i])
		{
			M=dp[i];
		}
	}
	len=0;
	if(M<=0)
		printf("Route %d has no nice parts\n",x);
	else
	{
		for(i=1;i<r;i++)
		{
			if(dp[i]==M && i+1-s[i]>len)
			{
				len=i+1-s[i];
				Mp=i;
			}
		}
		printf("The nicest part of route %d is between stops %d and %d\n",x,s[Mp],Mp+1);
	}
}
int main()
{
	int test,i,M,j;
	scanf("%d",&test);
	for(i=1;i<=test;i++)
	{
		scanf("%d",&r);
		for(j=1;j<r;j++)
		{
			scanf("%d",&list[j]);
			dp[j]=1;
		}
		MSS(i);
	}
	return 0;
}
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

int dp[100];
void set_dp()
{
	int i;
	dp[1]=1;//{1}
	dp[2]=2;//{1} {2}
	dp[3]=2;//{1,3} {2}
	for(i=4;i<=76;i++)
		dp[i]=dp[i-2]+dp[i-3];//�]���D�حn�D�Ҳզ����϶��A�������i�H�A��J��L�Ʀr�A�ҥH�u��O
}							  //�Pi-2 ��i-3������group�i�զ�i��group
int main()
{
	int n;
	set_dp();
	while(scanf("%d",&n)!=EOF)
	{	
		printf("%d\n",dp[n]);
	}
	return 0;
}
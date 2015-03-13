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
		dp[i]=dp[i-2]+dp[i-3];//因為題目要求所組成的區間，中間不可以再塞入其他數字，所以只能是
}							  //與i-2 跟i-3結尾的group可組成i的group
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
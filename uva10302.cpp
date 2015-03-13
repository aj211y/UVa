#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>

long long int ans[50005];
int main()
{
	long long int i;
	int n;
	memset(ans,0,sizeof(ans));
	for(i=1;i<50005;i++)
	{
		ans[i]=ans[i-1]+i*i*i;
	}
	while(scanf("%d",&n)!=EOF)
	{
		printf("%lld\n",ans[n]);
	}
	return 0;
}
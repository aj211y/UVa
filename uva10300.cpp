#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int main()
{
	int test,num;
	long long int m,n,v,ans;
	scanf("%d",&test);
	while(test--)
	{
		ans=0;
		scanf("%d",&num);
		while(num--)
		{
			scanf("%lld%lld%lld",&m,&n,&v);
			ans+=m*v;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
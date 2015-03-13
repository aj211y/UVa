#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;


long long int func(long long int m,long long int M)
{
	long long int i,tmp,count,ret=0;
	for(i=m;i<=M;i++)
	{
		count=1;
		tmp=i;
		while(tmp!=1)
		{
			if(tmp%2)
				tmp=3*tmp+1;
			else
				tmp=tmp/2;
			count++;
		}
		ret=max(count,ret);
	}
	return ret;
}
int main()
{
	long long int a,b,i,m,M,ret;
	while(scanf("%lld%lld",&a,&b)!=EOF)
	{
		m=(a<b)?a:b;
		M=(a>b)?a:b;
		ret = func(m,M);
		printf("%lld %lld %lld\n",a,b,ret);
	}
	return 0;
}
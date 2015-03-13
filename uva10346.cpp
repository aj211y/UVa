#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

int main()
{
	int n,k,ans,tmp;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		ans=n;
		while(n/k>0)
		{
			ans+=n/k;
			tmp=n%k;
			n=n/k+tmp;
		}
		printf("%d\n",ans);
	}
	return 0;
}
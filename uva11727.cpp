#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main()
{
	int t,i,a,b,c,ans;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(a<=b && a>=c || a<=c && a>=b)
			ans=a;
		else if(b<=a && b>=c || b<=c && b>=a)
			ans=b;
		else //if(c<=a && c>=b || c<=b && c>=a)
			ans=c;
		printf("Case %d: %d\n",i,ans);
	}
	return 0;
}
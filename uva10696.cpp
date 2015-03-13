#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int mac(int n)
{
	if(n>=101)
		return n-10;
	else
		return mac(mac(n+11));
}
int main()
{
	int n;
	while(scanf("%d",&n)&&n!=0)
	{
		printf("f91(%d) = %d\n",n,mac(n));
	}
	return 0;
}
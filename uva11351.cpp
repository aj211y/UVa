#include<iostream>
#include<cstdio>
using namespace std;

int killer(int n,int m)
{
	if(n==1)
		return 0;
	return (killer(n-1,m)+m)%n;
}
int main()
{
	int t,i,n,m;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		scanf("%d%d",&n,&m);
		printf("Case %d: %d\n",i,killer(n,m)+1);
	}
	return 0;
}
#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int n,test=1;
	while(scanf("%d",&n)&&n){
		printf("Case %d: %d\n",test++,n/2);
	}
	return 0;
}
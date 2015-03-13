#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

long long int list[101][101];//C N ¨ú M= list[N][M]
int main()
{
	long long int N,M;
	memset(list,0,sizeof(list));
	list[1][0]=list[1][1]=1;
	for(int i=2,j=1;i<=100;i++)
	{
		list[i][0]=1;
		while(j<=i)
		{
			list[i][j]=list[i-1][j]+list[i-1][j-1];
			j++;
		}
		j=1;
	}
	while(scanf("%lld%lld",&N,&M)!=EOF)
	{
		if(N==0 && M ==0)
			break;
		printf("%lld things taken %lld at a time is %lld exactly.\n",N,M,list[N][M]);
	}
	return 0;
}
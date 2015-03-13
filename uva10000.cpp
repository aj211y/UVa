#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define INF -1000
using namespace std;

int list[120][120],n,s,test=1;
void Floyd()
{
	int i,j,k,M,Mp;
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(list[i][k]+list[k][j] > list[i][j])
				{
					list[i][j]=list[i][k]+list[k][j];
				}
			}
		}
	}
	M=0;
	Mp=0;
	for(i=1;i<=n;i++)
	{
		if(list[s][i]>M)
		{
			M=list[s][i];
			Mp=i;
		}
	}
	printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",test++,s,M,Mp);
}
int main()
{
	int i,j,a,b;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(i==j)
					list[i][j]=0;
				else
					list[i][j]=INF;
			}
		}
		scanf("%d",&s);
		while(scanf("%d%d",&a,&b))
		{
			if(a==0&&b==0)
				break;
			list[a][b]=1;
		}
		Floyd();
	}
	return 0;
}
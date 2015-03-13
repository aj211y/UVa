#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#define INF 1000000
using namespace std;

int C,S,dis[120][120];
void Floyd()
{
	int i,j,k;
	for(k=1;k<=C;k++)
	{
		for(i=1;i<=C;i++)
		{
			for(j=1;j<=C;j++)
			{
				if(max(dis[i][k],dis[k][j])<dis[i][j])
					dis[i][j]=max(dis[i][k],dis[k][j]);
			}
		}
	}
}
int main()
{
	int Q,i,j,a,b,len,cases=1;
	bool space=false;
	while(scanf("%d%d%d",&C,&S,&Q)!=EOF)
	{
		if(C==0 && S==0 && Q==0)
			break;
		if(space)
			printf("\n");
		space=true;
		for(i=1;i<=C;i++)
		{
			for(j=1;j<=C;j++)
			{
				if(i==j)
					dis[i][j]=0;
				else
					dis[i][j]=INF;
			}	
		}
		for(i=1;i<=S;i++)
		{
			scanf("%d%d%d",&a,&b,&len);
			dis[a][b]=len;//這題是雙向邊
			dis[b][a]=len;
		}
		Floyd();
		printf("Case #%d\n",cases++);
		for(i=0;i<Q;i++)
		{
			scanf("%d%d",&a,&b);
			if(dis[a][b]==INF)
				printf("no path\n");
			else
				printf("%d\n",dis[a][b]);
		}
	}
	return 0;
}
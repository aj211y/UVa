#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int list[600][600];
int GCD(int x,int y)//y¤ñ¸û¤j
{
	if(list[x][y]!=0)
		return list[x][y];
	if(y%x==1)
		return list[x][y]=1;
	if(y%x==0)
		return list[x][y]=x;
	return GCD(y%x,x);
}
int main()
{
	int G,i,j,k,N,ans[600];
	memset(list,0,sizeof(list));
	memset(ans,0,sizeof(ans));
	for(i=1;i<=500;i++)
		list[1][i]=1;
	
	while(scanf("%d",&N)!=EOF)
	{
		if(N==0)
			break;
		if(ans[N]==0)
		{
			G=0;
			for(i=1;i<N;i++)
			{
				for(j=i+1;j<=N;j++)
				{
					G+=GCD(i,j);//i<j
				}
			}
			ans[N]=G;
		}
		printf("%d\n",ans[N]);
	}
	return 0;
}
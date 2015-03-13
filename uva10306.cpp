/*
	�@��coin�P�ɦ���ӻ���x��y
	x^2 + y^2 = S^2
	way[i][j]�N�� x���`�M=i �M y���`�M=j �ɪ��ֵ̤w����
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF 9999999
using namespace std;

int v1[50],v2[50],way[310][310];
int main()
{
	int test,m,S,i,j,k,ans;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&m,&S);
		//initial
		for(i=0;i<310;i++)
			for(j=0;j<310;j++)
				way[i][j]=INF;
		
		//�U��coin������
		for(i=0;i<m;i++)
			scanf("%d%d",&v1[i],&v2[i]);
		//�O���o�@��case���Ҧ�way
		way[0][0]=0;
		for(i=0;i<m;i++)
		{
			for(j=v1[i];j<=S;j++)
			{
				for(k=v2[i];k<=S;k++)
				{
					way[j][k]=min(way[j][k],way[j-v1[i]][k-v2[i]]+1);
				}
			}
		}
		
		ans=INF;
		for(i=0;i<=S;i++)
		{
			for(j=0;j<=S;j++)
			{
				if(way[i][j]!=INF && (i*i+j*j)==S*S)
				{
					ans=min(ans,way[i][j]);
				}
			}
		}
		if(ans==INF)
			printf("not possible\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}
//�����O��i�ӪF��n��b���@�Ӧ�m�W
/*
item | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@
pos  | 3 | 1 | 2 | 4 | 9 | 5 | 10| 6 | 8 |  7 |
��ڪ��~���\�]�ˤl =>
item | 2 | 3 | 1 | 4 | 6 | 8 | 10| 9 | 5 |  7 |
�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@
�s�� | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |

�ǥͪ���J
pos  | 2 | 10| 1 | 3 | 8 | 4 | 9 | 5 | 7 |  6 |
�n���ন��ڪ��~�\�]���ˤl =>
item | 3 | 1 | 4 | 6 | 8 | 10| 9 | 5 | 7 |  2 |
�i�H�o�{�P��ڪ��~���\�]�ˤl�ܹp�P�A���O�{�b�n��L�ন�Ʀr�A�o�˨DLIS�����K
�ন�s��=>
�s�� | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10|  1 |

*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int n,i,list[30],dp[30],item[30],correct[30];
void LIS()
{
	int i,j,ans;
	ans=1;
	for(i=2;i<=n;i++)
	{
		for(j=1;j<i;j++)
		{
			if(list[i]>list[j] && dp[j]+1 > dp[i])
			{
				dp[i]=dp[j]+1;
			}
		}
		if(dp[i]>ans)
			ans=dp[i];
	}
	printf("%d\n",ans);
}
int main()
{
	int data;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&correct[i]);
	//�ݤW�誺���ѡA�i�H�o�{���Ѫ�������F�⦸(����S��)�A�ҥH�o�̪����N
	//correct[x]=y => item x���s���Oy
	while(scanf("%d",&data)!=EOF)
	{
		item[data]=1;//item[x]=y => ��mx���a����item y
		for(i=2;i<=n;i++)
		{
			scanf("%d",&data);
			item[data]=i;
		}
		for(i=1;i<=n;i++)
		{
			dp[i]=1;
			list[i]=correct[item[i]];
			//printf("%d ",list[i]);
		}
		//printf("\n");
		LIS();
	}
	return 0;
}
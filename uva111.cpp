//給的是第i個東西要放在哪一個位置上
/*
item | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
一一一一一一一一一一一一一一一一一一一一一一一一
pos  | 3 | 1 | 2 | 4 | 9 | 5 | 10| 6 | 8 |  7 |
實際物品的擺設樣子 =>
item | 2 | 3 | 1 | 4 | 6 | 8 | 10| 9 | 5 |  7 |
一一一一一一一一一一一一一一一一一一一一一一一一
編號 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |

學生的輸入
pos  | 2 | 10| 1 | 3 | 8 | 4 | 9 | 5 | 7 |  6 |
要先轉成實際物品擺設的樣子 =>
item | 3 | 1 | 4 | 6 | 8 | 10| 9 | 5 | 7 |  2 |
可以發現與實際物品的擺設樣子很雷同，但是現在要把他轉成數字，這樣求LIS比較方便
轉成編號=>
編號 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10|  1 |

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
	//看上方的註解，可以發現正解的部分轉了兩次(等於沒轉)，所以這裡直接將
	//correct[x]=y => item x的編號是y
	while(scanf("%d",&data)!=EOF)
	{
		item[data]=1;//item[x]=y => 位置x的地方放著item y
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
//DP-LIS
//O(n^2)
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string> //atoi
#include <stack>
#define MAX 1000
using namespace std;

int list[MAX],p[MAX],dp[MAX];
//這裡的dp[i]存的就是以第i個數字結尾的最長遞增子序列
char buffer[MAX/10];
int main()
{
	int T,num,n,M,M_end,i;
	bool first=true;
	stack <int> ans;
	scanf("%d\n",&T);
	while(T--)
	{
		if(!first)
			printf("\n");
		first=false;
		n=0;
		while(fgets(buffer,sizeof(buffer),stdin))
		{
			//如果讀到單一個換行，表示此筆測資結束
			if(buffer[0]=='\n')
				break;
			num=atoi(buffer); //include <string>
			list[n++]=num;
		}
		for(i=0;i<n;i++)
		{
			//每個人最初的LIS長度為1
			dp[i]=1;
			//每個人原本的parent為自己
			p[i]=i;
		}
		//LIS
		//i=0時(第一個數字)，必為 第一個數結尾的LIS
		M=1;
		M_end=0;
		for(i=1;i<n;i++)
		{
			for(int j=i-1;j>=0;j--)
			{
				//如果第i個數比第j個數大(表示可以接在第j個數後面)
				//且 以第j個數結尾的長度+1 比 以第i個數結尾的長度 長的話
				//則更新 長度dp 來自哪裡(p)
				if(list[i]>list[j] && dp[j]+1>dp[i])
				{
					dp[i]=dp[j]+1;
					p[i]=j;
				}
			}
			if(M<dp[i])
			{
				M=dp[i];
				M_end=i;
			}
		}
		printf("Max hits: %d\n",M);
		
		for(i=M_end;i!=p[i];i=p[i])
			ans.push(list[i]);
		ans.push(list[i]);
		while(!ans.empty())
		{
			printf("%d\n",ans.top());
			ans.pop();
		}
	}
	return 0;
}
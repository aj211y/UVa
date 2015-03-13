#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define Max 30
using namespace std;

int list[Max][Max],sum[Max],dp[Max],len,row;

void MSS()
{
	int i,j,M,M_dp,k,r;
	M=0;
	for(j=0;j<row;j++)//從第各行開始的各種矩形解
	{
		//從第j行開始的第一種矩形解 -- 1*len大小的矩形
		sum[0]=list[j][0];
		dp[0]=list[j][0];
		M_dp=dp[0];
		for(i=1;i<len;i++)
		{
			dp[i]=list[j][i]==0?0:dp[i-1]+1;
			sum[i]=list[j][i]==0?0:1;
			M_dp=dp[i]>M_dp?dp[i]:M_dp;
		}
		M=M_dp*1>M?M_dp*1:M;
		//從第j行開始的各種矩形解
		for(k=j+1;k<row;k++)
		{
			r=k-j+1;//r為現在矩形的寬度 也就是佔了幾行
			//一行一行加入sum[]中
			for(i=0;i<len;i++)
				sum[i]+=list[k][i];
			dp[0]=sum[0]==r?1:0;
			M_dp=dp[0];
			
			for(i=1;i<len;i++)
			{
				if(sum[i]==r)//加起來跟當前寬度r一樣，表示上下有一直連續下來
				{
					dp[i]=dp[i-1]+1;
					if(dp[i]>M_dp)
						M_dp=dp[i];
				}
				else//只要不等於當前寬度r，就表示沒有一直連續下來
					dp[i]=0;
			}
			M=(M_dp*r)>M?(M_dp*r):M;
		}
		
	}
	printf("%d\n",M);
}
int main()
{
	int test,i;
	string str;
	bool space=false;
	scanf("%d",&test);
	getchar();
	getchar();
	while(test--)
	{
		if(space)
			printf("\n");
		space=true;
		row=0;	
		while(getline(cin,str))
		{
			if(str=="\0")
				break;
			for(i=0;i<str.size();i++)
				list[row][i]=str[i]-48;
			row++;
			len=str.size();
		}
		MSS();
	}
	return 0;
}
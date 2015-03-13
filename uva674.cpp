/*
	coin change
	有 1 5 10 25 50 這五種硬幣 
	給你一個錢的數目，問可有幾種硬幣組合
	dp~~~~~~~完全背包問題
	
	通常背包問題會想到要放多少值進去
	這題要放的是 " 方法數 "
	
 $$  0 1 2 3 4 5 6 7 8 9 10...
    ------------------------
	 1 1 1 1 1 1 1 1 1 1  1...用1元硬幣組成的方法數
	 . . . . . 2 2 2 2 2  3...用5元硬幣組成的方法數
	 
	 狀態轉移方程：f[n]=f[n-coin[i]];//coin[i]代表現在是用哪一種硬幣再替換
									 //n-coin[i]代表目前的n元中以一個coin[i]做替換
									 //所以要讓自己的組合數加上(n-coin[i])元所有的組合數
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define Max 8000 //此題要求最多要解的出7489
using namespace std;

int way[Max];
int coin[5]={1,5,10,25,50};
int main()
{
	int i,j,n;
	memset(way,0,sizeof(way));
	way[0]=1;
	for(i=0;i<5;i++)//哪一個硬幣
	{
		for(j=coin[i];j<8000;j++)  //概念是要用 "一個" 硬幣i 來替換j元 也就是說j元=coin[i]+剩下的$
		{						   //剩下的$又有很多組合的可能，這時不要重複計算，往前找他的dp值就好
			way[j]+=way[j-coin[i]];//所以j元=coin[i]+剩下的$ 這樣的組合數就是剩下的$的所有組合數
		}						   //而j元的組合數即為原本的組合數跟j元=coin[i]+剩下的$這樣的組合數加總
	}
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d\n",way[n]);
	}
	return 0;
}
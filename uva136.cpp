/*
目的：尋找只由2 3 5這三個質因數組成的數列
找第N項時，就去比較
	"第N-1項 *2 會大於第N項的那項"
	"第N-1項 *3 會大於第N項的那項"
	"第N-1項 *5 會大於第N項的那項"
最小的那項就是第N項

找N+1項時
可以從 "乘2會大於第N-1項的那項" 繼續往後找
這也就是為什麼底下要以m2 m3 m5來記錄是哪一項
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

int main()
{
	int m2=0,m3=0,m5=0,i;
	int ugly[1510]={1};
	int pre_n=1;
	
	for(i=1;i<1500;i++)
	{
		for(;m2<i;m2++)
			if(ugly[m2]*2 > pre_n) 
				break;
		for(;m3<i;m3++)
			if(ugly[m3]*3 > pre_n)
				break;
		for(;m5<i;m5++)
			if(ugly[m5]*5 > pre_n)
				break;
		pre_n=min(ugly[m5]*5,min(ugly[m2]*2,ugly[m3]*3));
		ugly[i]=pre_n;
	}
	printf("The 1500'th ugly number is %d.\n",ugly[1499]);
	return 0;
}
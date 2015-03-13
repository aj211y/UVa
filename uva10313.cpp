#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

long long int way[310][310];
int main()
{
	string str;
	long long int i,j,N,L1,L2,count;
	memset(way,0,sizeof(way));
	way[0][0]=1;
	/*for(i=0;i<310;i++)
	{
		way[0][i]=1;//$$=0 時，用各種硬幣組成的解法只有一個 **就是都不拿**
		way[1][i]=1;//$$=1 時，用各種硬幣組成的解法也只有一個 **就是用1元硬幣**
	}*/
	for(i=1;i<310;i++)
	{
		for(j=0;j<310;j++)
		{
			if(i>j)
				way[i][j]=way[i-1][j];
			else
				way[i][j]=way[i-1][j]+way[i][j-i];
		}
	}
	while(getline(cin,str))
	{
		count=0;
		N=0;
		L1=0;
		L2=0;
		for(i=0;i<str.size();i++)
		{
			if(str[i]==' ')
			{
				count++;
				continue;
			}
			if(count==0)//N
				N=N*10+(str[i]-48);
			else if(count==1)//L1
				L1=L1*10+(str[i]-48);
			else//L2
				L2=L2*10+(str[i]-48);
		}
		
		if(L1>300)
			L1=300;
		if(L2>300)
			L2=300;
		if(count==0)//N
			printf("%lld\n",way[N][N]);
		else if(count==1)//N L1
			printf("%lld\n",way[L1][N]);
		else
		{
			if(L1==0||L1==1)
				printf("%lld\n",way[L2][N]);
			else
				printf("%lld\n",way[L2][N]-way[L1-1][N]);
		}
	}
	return 0;
}
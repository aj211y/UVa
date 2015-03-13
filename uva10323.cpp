//陰險至極=  =
//輸入的也有可能是負號
//依公式f(n)=n*f(n-1) -> f(n-1)=f(n)/n 
//代入n=-1 得 f(-1)=f(0)/0=1/0 也就是正無限大!!!!!!!!!!!!!!!馬的=  =
//同理n=-2 f(-2)=f(-1)/-1 變成負無限大  剩下的就是一直正負交替
//馬的!!!!!!!!!!!!!!!!!!!!!
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

unsigned long long int list[20];
bool visited[20];
unsigned long long int fab(unsigned long long int n)
{
	if(n==0)
		return 1;
	else if(visited[n])
		return list[n];
	else
		return n*fab(n-1);
}
int main()
{
	int n;
	unsigned long long int i;
	memset(visited,false,sizeof(visited));
	memset(list,0,sizeof(list));
	for(i=0;i<20;i++)
	{
		list[i]=fab(i);
		visited[i]=true;
	}
	while(scanf("%d",&n)!=EOF)
	{
		if(n<0)
		{
			if((-n)%2)
				printf("Overflow!\n");//正無限大
			else
				printf("Underflow!\n");//負無限大
		}
		else if(n<8)
			printf("Underflow!\n");
		else if(n>13)
			printf("Overflow!\n");
		else
			printf("%llu\n",list[n]);
	}
	return 0;
}
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;

int list[100000];
bool visited[100000];
int happy(int n)
{
	int tmp=0,i;
	i=n;
	while(i>0)
	{
		tmp+=pow(i%10,2);
		i=i/10;
	}
	if(visited[tmp])
	{
		if(list[tmp]>0)
			return list[tmp]+1;
		else 
			return 0;
	}
	else
	{
		list[tmp]=happy(tmp);
		visited[tmp]=true;
		if(list[tmp])
			return list[tmp]+1;
		else
			return i;
	}
}
int main()
{
	int L,H,i;
	bool flag=false;
	memset(list,0,sizeof(list));
	memset(visited,false,sizeof(visited));
	list[1]=1;
	list[7]=6;
	list[10]=2;
	list[13]=3;
	list[19]=5;
	for(i=0;i<=20;i++)
		visited[i]=true;
	for(i=21;i<=99999;i++)
	{
		if(!visited[i])
			list[i]=happy(i);
		visited[i]=true;
	}
	while(scanf("%d%d",&L,&H)!=EOF)
	{
		if(flag)
			printf("\n");
		flag=true;
		for(i=L;i<=H;i++)
		{
			if(list[i])
				printf("%d %d\n",i,list[i]);
		}
	}
	return 0;
}
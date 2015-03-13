/*
wormholes
n stars (0~n-1) 1<=n<=1000
m wormholes     0<=m<=2000
t time          -1000<=t<=1000
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define INF 1000010 //most stars * largest time =1000*1000
using namespace std;

struct node
{
	int start,end,time;
}list[2100];
int star[1100],n,m;
void relax(int start,int end,int time)
{
	if(star[start]+time < star[end])
		star[end]=star[start]+time;
}
void BellmanFord()
{
	int i,j,start,end,time;
	bool possible=false;
	//init
	for(i=0;i<n;i++)
		star[i]=INF;
	//n-1 times
	for(i=0;i<n-1;i++)
		for(j=0;j<m;j++)
			relax(list[j].start,list[j].end,list[j].time);
	for(j=0;j<m;j++)
	{
		start=list[j].start;
		end=list[j].end;
		time=list[j].time;
		if(star[start]+time < star[end])
			possible=true;
	}
	if(possible)
		printf("possible\n");
	else
		printf("not possible\n");
}
int main()
{
	int test,i;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<m;i++)
			scanf("%d%d%d",&list[i].start,&list[i].end,&list[i].time);
		BellmanFord();
	}
	return 0;
}
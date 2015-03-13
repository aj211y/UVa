#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#define Max 1000000
using namespace std;

int point[Max],n,energy[Max];
bool inQ[Max];
vector<int> list[Max];
void SPFA()
{
	queue<int> wait;
	int tmp,i,des;
	memset(inQ,false,sizeof(inQ));
	memset(energy,0,sizeof(energy));
	wait.push(1);
	inQ[1]=true;
	energy[1]=100;
	while(!wait.empty())
	{
		tmp=wait.front();
		wait.pop();
		inQ[tmp]=false;
		//printf("tmp-%d\n",tmp);
		for(i=0;i<list[tmp].size();i++)
		{
			des=list[tmp][i];
			if(energy[tmp]+point[des] > energy[des] && energy[des]<10000)
			{
				energy[des]=energy[tmp]+point[des];
				if(!inQ[des])
				{
					inQ[des]=true;
					wait.push(des);
				}
			}
			//printf("energy-%d des-%d\n",energy[des],des);
		}
	}
	if(energy[n]<=0)
		printf("hopeless\n");
	else
		printf("winnable\n");
}
int main()
{
	int i,j,num,des;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==-1)
			break;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&point[i]);
			scanf("%d",&num);
			for(j=0;j<num;j++)
			{
				scanf("%d",&des);
				list[i].push_back(des);
			}
		}
		
		SPFA();
		for(i=1;i<=n;i++)
			list[i].clear();
	}
	return 0;
}
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

struct node
{
	double x,y;
}gopher[120],hole[120];
vector <int> list[120];//記錄左邊點的連到右邊哪些點

bool used[120];//右邊的點用過了沒
int rlink[120],llink[120];
bool DFS(int now)
{
	int i,next;
	//掃過這一點所有相連的邊
	for(i=0;i<list[now].size();i++)
	{
		next=list[now][i];
		if(!used[next])
		{
			used[next]=true;
			//右邊這點沒有match過，或者他可以跟別人match，把這個位置讓出來
			if(!rlink[next]||DFS(rlink[next]))
			{
				llink[now]=next;
				rlink[next]=now;
				return true;
			}
		}
	}
	//找不到可以match的
	return false;
}
int bipartite(int L,int R)
{
	int i,ans=0;
	//左邊跟右邊都還沒有match的對象
	memset(rlink,0,sizeof(rlink));
	memset(llink,0,sizeof(llink));
	for(i=1;i<=L;i++)
	{
		memset(used,false,sizeof(used));//右邊的點都還沒用過
		if(DFS(i))
			ans++;
	}
	return ans;
}
int main()
{
	int n,m,s,v,i,j,num;
	double limit;
	while(scanf("%d%d%d%d",&n,&m,&s,&v)!=EOF)
	{
		memset(list,0,sizeof(list));
		limit=s*v;//一隻最多可跑的距離
		//the position a gopher stands
		for(i=1;i<=n;i++)
			scanf("%lf%lf",&gopher[i].x,&gopher[i].y);
		for(i=1;i<=m;i++)
			scanf("%lf%lf",&hole[i].x,&hole[i].y);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(sqrt(pow(hole[j].x-gopher[i].x,2)+pow(hole[j].y-gopher[i].y,2))<=limit)
					list[i].push_back(j);
			}
		}
		num=bipartite(n,m);
		printf("%d\n",n-num);
	}
	return 0;
}
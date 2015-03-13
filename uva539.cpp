#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int list[30][30],Max,n,step;
bool visited[30][30];
void dfs(int x,int y)
{
	visited[x][y]=true;
	visited[y][x]=true;
	step++;
	if(Max<step)
		Max=step;
	//printf("%d -> %d\n",x,y);
	//printf("step =%d  Max =%d\n",step,Max);
	for(int i=0;i<n;i++)
	{
		if(!visited[y][i]&& list[y][i]==1)
		{
			dfs(y,i);
		}
	}
	step--;
	visited[x][y]=false;
	visited[y][x]=false;
}
int main()
{
	int m,a,b;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(list,0,sizeof(list));
		memset(visited,false,sizeof(visited));
		Max=0;
		step=0;
		if(n==0 && m==0)
			break;
		while(m--)
		{
			scanf("%d%d",&a,&b);
			list[a][b]=1;
			list[b][a]=1;
		}
		for(a=0;a<n;a++)
		{
			for(b=0;b<n;b++)
			{
				if(list[a][b]==1)
					dfs(a,b);
					//printf("%d -> %d\n",a,b);
			}
		}
		printf("%d\n",Max);
	}
}
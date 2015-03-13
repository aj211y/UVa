#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAX 30
using namespace std;

char matrix[MAX][MAX];
bool visited[MAX][MAX];
static int step[8][2]={{-1,-1},{0,-1},{1,-1},{-1,0},{1,0},{-1,1},{0,1},{1,1}};
int n;
bool overEdge(int i,int j)
{
	if(i>=0 && i<n && j>=0 && j<n)
		return false;
	else
		return true;
}

void DFS(int i,int j)
{
	int a,nextI,nextJ;
	visited[i][j]=true;
	for(a=0;a<8;a++)
	{
		nextI=i+step[a][0];
		nextJ=j+step[a][1];
		if(!overEdge(nextI,nextJ)&&matrix[nextI][nextJ]=='1'&&!visited[nextI][nextJ])
		{
			DFS(nextI,nextJ);
		}
	}
}

int main()
{
	int i,j,ans;
	int img=1;
	while(scanf("%d",&n)!=EOF)
	{
		memset(visited,false,sizeof(visited));
		memset(matrix,'0',sizeof(matrix));
		/*for(i=0;i<MAX;i++)
			for(j=0;j<MAX;j++)
				matrix[i][j]='0';*/
		ans=0;
		for(i=0;i<n;i++)
			scanf("%s",matrix[i]);
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(matrix[i][j]=='1'&& !visited[i][j])
				{
					DFS(i,j);
					ans++;
				}				
			}
		}
		printf("Image number %d contains %d war eagles.\n",img++,ans);
	}
	return 0;
}
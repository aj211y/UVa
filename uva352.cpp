#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
bool visited[28][28]={false};
char map[28][28]={0};
int n,step[8][2]={{-1,-1},{0,-1},{1,-1},{-1,0},{1,0},{-1,1},{0,1},{1,1}};

bool check(int i,int j){
	if(i<0||j<0||i>n||j>n)
		return false;
	else
		return true;
}
void DFS(int i,int j)
{
	//printf("DFS%d %d\n",i,j);
	int a,tmpi,tmpj;
	if(map[i][j]=='1'&&visited[i][j]==false){
		visited[i][j]=true;
		for(a=0;a<8;a++){
			tmpi=i+step[a][0];
			tmpj=j+step[a][1];
			if(check(tmpi,tmpj)&&map[tmpi][tmpj]=='1')
				DFS(tmpi,tmpj);
		}
	}
}
int main()
{
	int i,j,count=0,t=1;
	while(scanf("%d",&n)!=EOF){
		count=0;
		for(i=0;i<n;i++){
			scanf("%s",&map[i]);
		}
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(map[i][j]=='1'&&visited[i][j]==false){
					//printf("*%d %d\n",i,j);
					DFS(i,j);
					count++;
				}
			}
		}
		printf("Image number %d contains %d war eagles.\n",t++,count);
		memset(map,'\0',sizeof(map));
		memset(visited,false,sizeof(visited));
	}
	return 0;
}
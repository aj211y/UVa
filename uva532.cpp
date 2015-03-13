#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
char maze[35][35][35];
int visited[35][35][35]={0};
bool flag=false;
int ans,level,row,col;
int step[6][3]={{-1,0,0},{1,0,0},{0,1,0},{0,0,1},{0,-1,0},{0,0,-1}};//上下前左後右
struct point
{
	int i,j,k,count;
};
queue<point> list;

bool check(int i,int j,int k)
{
	if(i<0||j<0||k<0||i>=level||j>=row||k>=col)
		return false;
	else{
		if(maze[i][j][k]=='#')
			visited[i][j][k]=-1;
		return true;
	}
}
void bfs(int i,int j,int k,int count)
{
	int a,nexti,nextj,nextk;
	point dot;
	visited[i][j][k]=++count;
	dot.i=i;
	dot.j=j;
	dot.k=k;
	dot.count=count;
	list.push(dot);
	while(!list.empty()){
		for(a=0;a<6;a++){
			nexti=list.front().i+step[a][0];
			nextj=list.front().j+step[a][1];
			nextk=list.front().k+step[a][2];
			if(check(nexti,nextj,nextk)&&visited[nexti][nextj][nextk]==0){
				dot.i=nexti;
				dot.j=nextj;
				dot.k=nextk;
				dot.count=list.front().count+1;
				list.push(dot);
				visited[nexti][nextj][nextk]=dot.count;
				if(maze[nexti][nextj][nextk]=='E' && !flag){
					ans=dot.count-1;
					flag=true;
				}
			}
		}
		list.pop();
	}
}

int main()
{
	int i,j,k,si,sj,sk;
	while(scanf("%d%d%d",&level,&row,&col) && (level|row|col)){
		flag=false;
		ans=0;
		for(i=0;i<level;i++){
			getchar();
			for(j=0;j<row;j++){
				for(k=0;k<col;k++){
					scanf("%c",&maze[i][j][k]);
					if(maze[i][j][k]=='S'){
						si=i;
						sj=j;
						sk=k;
					}
				}
				getchar();
			}
		}
		bfs(si,sj,sk,0);
		if(flag)
			printf("Escaped in %d minute(s).\n",ans);
		else
			printf("Trapped!\n");
		for(i=0;i<level;i++){
			for(j=0;j<row;j++){
				for(k=0;k<col;k++){
					visited[i][j][k]=0;
				}
			}
		}
	}
	return 0;
}
#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int step[8][2]={{-2,-1},{-1,-2},{1,2},{2,1},{-2,1},{-1,2},{1,-2},{2,-1}};
int ans;
bool flag;
bool visited[10][10]={false};
struct point
{
	int x,y,count;
};
queue<point> list;
point data2;


bool check(int x,int y)
{
	if(x<0 || y < 0 || x>=8 || y >=8)
		return false;
	else
		return true;
}
void bfs(point data)
{
	int i;
	visited[data.x][data.y]=true;
	point dot;
	list.push(data);
	while(!list.empty()){
		for(i=0;i<8;i++){
			dot.x=list.front().x+step[i][0];
			dot.y=list.front().y+step[i][1];
			if(check(dot.x,dot.y)&&!visited[dot.x][dot.y]){
				visited[dot.x][dot.y]=true;
				dot.count=list.front().count+1;
				if(dot.x==data2.x&&dot.y==data2.y && !flag){
					flag=true;
					ans=dot.count;
				}
				list.push(dot);
			}
		}
		list.pop();
	}
}
int main()
{
	int i,j;
	char cha1,cha2;
	point data1;
	while(scanf("%c%d %c%d",&cha1,&data1.x,&cha2,&data2.x)!=EOF){
		flag=false;
		data1.count=0;
		data1.y=cha1-97;
		data2.y=cha2-97;
		data1.x--;
		data2.x--;
		if(data1.x==data2.x && data1.y==data2.y)
			ans=0;
		else
			bfs(data1);
		printf("To get from %c%d to %c%d takes %d knight moves.\n",cha1,data1.x+1,cha2,data2.x+1,ans);
		for(i=0;i<10;i++){
			for(j=0;j<10;j++){
				visited[i][j]=false;
			}
		}
		getchar();
	}
	return 0;
}
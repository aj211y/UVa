#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int matrix[500][500];
int mx[500],my[500],vy[500],row,col;

bool DFS(int x)
{
	int y;
	for(y=0;y<col;y++){
		if(matrix[x][y]&&!vy[y]){
			vy[y]=1;
			if(my[y]==-1 || DFS(my[y])){//如果沒有連到那點，則找到一個匹配||DFS(my[y]) 去找對應此y點的x點，看有沒有另一個匹配的邊，有的話就多找到一條擴充路徑
				mx[x]=y;
				my[y]=x;
				return true;
			}
		}
	}
	return false;
}
int bi_matching()
{
	int x,max=0;
	memset(mx,-1,sizeof(mx));
	memset(my,-1,sizeof(my));
	for(x=0;x<row;x++){
		if(mx[x]==-1){//表示未matching
			memset(vy,0,sizeof(vy));
			if(DFS(x))
				max++;
		}
	}
	return max;
}
int main()
{
	int tests,i,j,ans,t;
	scanf("%d",&tests);
	for(t=1;t<=tests;t++){
		memset(matrix,0,sizeof(matrix));
		scanf("%d%d",&row,&col);
		for(i=0;i<row;i++){
			for(j=0;j<col;j++){
				scanf("%d",&matrix[i][j]);
			}
		}
		ans=bi_matching();
		printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n",t,ans);
	}
	return 0;
}
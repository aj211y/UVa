#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;


int main()
{
	int v,spot,matrix[150][150]={0},tospot,n,i,j,k,start[150]={0};
	queue<int> ans;
	while(scanf("%d",&v)&&v){
		while(scanf("%d",&spot)&&spot){
			while(scanf("%d",&tospot)&&tospot)
				matrix[spot][tospot]=1;
		}
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&start[i]);
		for(k=1;k<=v;k++){
			for(i=1;i<=v;i++){
				for(j=1;j<=v;j++){
					if(!matrix[i][j])
						matrix[i][j] = matrix[i][j] | (matrix[i][k] & matrix[k][j]);
				}
			}
		}
		/*for(i=1;i<=v;i++){
			for(j=1;j<=v;j++){
				printf("%d ",matrix[i][j]);
			}
			printf("\n");
		}*/
		for(i=0;i<n;i++){
			for(j=1;j<=v;j++){
				if(!matrix[start[i]][j])
					ans.push(j);
			}
			printf("%d",ans.size());
			while(!ans.empty()){
				printf(" %d",ans.front());
				ans.pop();
			}
			printf("\n");
		}
		for(i=0;i<150;i++){
			for(j=0;j<150;j++){
				matrix[i][j]=0;
				start[i]=0;
			}
		}
	}
	return 0;
}
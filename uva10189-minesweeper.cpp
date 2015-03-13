#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

bool check(int i,int j,int n,int m)
{
	if(i<0 || j<0 || i>=n || j>=m)
		return false;
	else
		return true;
}
int main()
{
	int n,m,field=1,i,j,k,ni,nj;
	int farm[100][100]={0};
	string str;
	int step[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
	while(scanf("%d %d",&n,&m)!=EOF){
		if(n==0&&m==0)
			break;
		scanf("\n");
		for(i=0;i<n;i++){//紀錄原始farm陣列
			getline(cin,str);
			for(j=0;j<m;j++){
				if(str[j]=='*')
					farm[i][j]=9;//紀錄為有金礦的地方，選9是因為絕不會有一個地方加總後為9，加總後最多為8
				else
					farm[i][j]=0;//空的地方
			}
		}
		for(i=0;i<n;i++){//計算最後要輸出的樣子
			for(j=0;j<m;j++){
				if(farm[i][j]==9){//金礦的位置
					for(k=0;k<8;k++){//他的周遭
						ni=i+step[k][0];
						nj=j+step[k][1];
						if(check(ni,nj,n,m)){
							if(farm[ni][nj]!=9)//不為金礦
								farm[ni][nj]+=1;
						}
					}
				}
			}
		}
		if(field!=1)
			printf("\n");
		printf("Field #%d:\n",field);
		field++;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(farm[i][j]==9)
					printf("*");
				else
					printf("%d",farm[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
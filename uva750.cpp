#include<iostream>
#include<cstdio>
using namespace std;
bool my[8]={false},md1[15]={false},md2[15]={false};
int solution[8]={0},count=1,row,col;

void func(int x)
{
	if(x==8){
		if(count==1){
			printf("SOLN       COLUMN\n");
			printf(" #      1 2 3 4 5 6 7 8\n\n");
		}
		printf("%2d      ",count++);
		printf("%d",solution[0]+1);
		for(int i=1;i<8;i++)
			printf(" %d",solution[i]+1);
		printf("\n");
	}
	if(x==col-1){
		solution[x]=row-1;
		func(x+1);
	}
	for(int y=0;y<8;y++){
		int d1=(x+y)%15,d2=(y-x+15)%15;
		if(!my[y]&&!md1[d1]&&!md2[d2]){
			my[y]=md1[d1]=md2[d2]=true;
			solution[x]=y;
			func(x+1);
			my[y]=md1[d1]=md2[d2]=false;
		}
	}
}
int main()
{
	int set;
	scanf("%d",&set);
	while(set--){
		if(count!=1)
			printf("\n");
		count=1;
		scanf("%d %d",&row,&col);
		solution[col-1]=row-1;
		my[row-1]=md1[(row+col-2)%15]=md2[(row-col+15)%15]=true;
		func(0);
		my[row-1]=md1[(row+col-2)%15]=md2[(row-col+15)%15]=false;
	}
	return 0;
}
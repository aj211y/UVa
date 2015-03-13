#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int move,m;
int list[10],test=1,board[100][10],b=1,tmp[10];
bool row_used[10],diag1[20],diag2[20];
void backtrack(int len)
{
	int i,j,d1,d2,row;
	if(len==9)
	{
		for(i=1;i<=8;i++)
		{
			board[b][i]=tmp[i];
			//printf("%d",tmp[i]);
		}
		//printf("\n");
		b++;
	}
	else
	{
		for(row=1;row<9;row++)
		{
			d1=row-len+7;	
			d2=row+len;
			if(!row_used[row] && !diag1[d1] && !diag2[d2])
			{
				row_used[row]=true;
				diag1[d1]=true;
				diag2[d2]=true;
				tmp[len]=row;
				backtrack(len+1);
				row_used[row]=false;
				diag1[d1]=false;
				diag2[d2]=false;
			}
		}
	}
}
int main()
{
	memset(row_used,false,sizeof(row_used));
	memset(diag1,false,sizeof(diag1));
	memset(diag2,false,sizeof(diag2));
	memset(tmp,0,sizeof(tmp));
	backtrack(1);
	int i;
	memset(list,0,sizeof(list));
	while(scanf("%d%d%d%d%d%d%d%d",&list[1],&list[2],&list[3],&list[4],&list[5],&list[6],&list[7],&list[8])!=EOF)
	{
		m=10;
		for(i=1;i<b;i++)
		{
			move=0;//總移動步數
			if(list[1]!=board[i][1])
				move++;
			if(list[2]!=board[i][2])
				move++;
			if(list[3]!=board[i][3])
				move++;
			if(list[4]!=board[i][4])
				move++;
			if(list[5]!=board[i][5])
				move++;
			if(list[6]!=board[i][6])
				move++;
			if(list[7]!=board[i][7])
				move++;
			if(list[8]!=board[i][8])
				move++;
			if(move<m)
				m=move;
		}
		printf("Case %d: %d\n",test++,m);
	}
	return 0;
}
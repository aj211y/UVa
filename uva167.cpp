#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;


int list[70][70],board[100][10],b=1,tmp[10];
bool row_used[10],diag1[20],diag2[20];
void backtrack(int len)
{
	int d1,d2,i;
	if(len==9)
	{
		for(i=1;i<=8;i++)
			board[b][i]=tmp[i];
		b++;
	}
	else
	{
		for(i=1;i<=8;i++)
		{
			d1=i+len;
			d2=i-len+7;
			if(!row_used[i] && !diag1[d1] && !diag2[d2])
			{
				row_used[i]=true;
				diag1[d1]=true;
				diag2[d2]=true;
				tmp[len]=i;
				backtrack(len+1);
				row_used[i]=false;
				diag1[d1]=false;
				diag2[d2]=false;
			}
		}
	}
	
}
int main()
{
	memset(board,0,sizeof(board));
	memset(tmp,(int)'\0',sizeof(tmp));
	memset(row_used,false,sizeof(row_used));
	memset(diag1,false,sizeof(diag1));
	memset(diag2,false,sizeof(diag2));
	backtrack(1);
	
	int k,i,j,M,score;
	scanf("%d",&k);
	while(k--)
	{
		memset(list,0,sizeof(list));
		for(i=1;i<=8;i++)
		{
			for(j=1;j<=8;j++)
			{
				scanf("%d",&list[i][j]);
			}
		}
		M=0;
		for(i=1;i<b;i++)
		{
			score=list[board[i][1]][1]+list[board[i][2]][2]+list[board[i][3]][3]+list[board[i][4]][4]+list[board[i][5]][5]+list[board[i][6]][6]+list[board[i][7]][7]+list[board[i][8]][8];
			if(M<score)
				M=score;
		}
		printf("%5d\n",M);
	}
	return 0;
}
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;

int step[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
int vow=0;
bool existA[30],existB[30],visited[5][5];//board B���S���o�Ӧr��
char listA[5][5],listB[5][5],tmp[5];
set<string> wordA,ans;
void DFS_A(int row,int col,int len)
{
	int i,nx,ny;
	visited[row][col]=true;
	tmp[len]=listA[row][col];
	if(len==3)//���X�k�r
	{
		//cout << tmp << endl;
		wordA.insert((string)tmp);
		existA[tmp[0]-64]=true;
	}
	else
	{
		for(i=0;i<8;i++)
		{
			nx=row+step[i][0];
			ny=col+step[i][1];
			if(nx<=0||nx>4 || ny<=0 || ny >4)
				continue;
			/*
				nx=4;
			if(nx>4)
				nx=1;
			if(ny<=0)
				ny=4;
			if(ny>4)
				ny=1;*/
			if(!visited[nx][ny] && existB[(listA[nx][ny]-64)])
			{
				if(listA[nx][ny]=='A' || listA[nx][ny]=='E'||listA[nx][ny]=='I'||listA[nx][ny]=='O'||listA[nx][ny]=='U'||listA[nx][ny]=='Y')//�O����
				{
					if(vow<2)
					{
						vow++;
						DFS_A(nx,ny,len+1);
						vow--;
					}	
				}
				else//�D����
				{
					if((len+1-vow)==2)//len+1 ���ثe��F�X�ӼƦr vow���ثe�����r�� len+1-vow���ثe�l���r��
						continue;//�Y�l���r�Ƥw��2�A��ܥu�ʥ����F
					DFS_A(nx,ny,len+1);
				}
			}
		}
	}
	visited[row][col]=false;
}
void DFS_B(int row,int col,int len)
{
	int i,nx,ny;
	string str;
	visited[row][col]=true;
	tmp[len]=listB[row][col];
	if(len==3)//���X�k�r
	{
		str=tmp;
		//cout << str << endl;
		if(wordA.find(str)!=wordA.end())//���o�Ӧr
			ans.insert(str);
	}
	else
	{
		for(i=0;i<8;i++)
		{
			nx=row+step[i][0];
			ny=col+step[i][1];
			if(nx<=0||nx>4 || ny<=0 || ny >4)
				continue;
			/*
			if(nx<=0)
				nx=4;
			if(nx>4)
				nx=1;
			if(ny<=0)
				ny=4;
			if(ny>4)
				ny=1;*/
			if(!visited[nx][ny])
			{
				if(listB[nx][ny]=='A' || listB[nx][ny]=='E'||listB[nx][ny]=='I'||listB[nx][ny]=='O'||listB[nx][ny]=='U'||listB[nx][ny]=='Y')//�O����
				{
					if(vow<2)
					{
						vow++;
						DFS_B(nx,ny,len+1);
						vow--;
					}	
				}
				else//�D����
				{
					if((len+1-vow)==2)//len+1 ���ثe��F�X�ӼƦr vow���ثe�����r�� len+1-vow���ثe�l���r��
						continue;//�Y�l���r�Ƥw��2�A��ܥu�ʥ����F
					DFS_B(nx,ny,len+1);
				}
			}
		}
	}
	visited[row][col]=false;
}
void find_word_inA()
{
	int i,j;
	char c;
	//cout << "A" << endl;
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=4;j++)
		{
			c=listA[i][j];
			if(existB[(c-64)])//board B�]���o�Ӧr�A���N�h���ݦ��S���@�˪��X�k�r
			{
				//cout << c << endl;
				memset(visited,false,sizeof(visited));
				if(c=='A' || c=='E'||c=='I' || c=='O'||c=='U' || c=='Y')
					vow=1;
				else
					vow=0;
				DFS_A(i,j,0);
			}
		}
	}
}
void find_word_inB()
{
	int i,j;
	char c;
	//cout << "B" << endl;
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=4;j++)
		{
			c=listB[i][j];
			if(existA[c-64])//board A���o�Ӧr�������X�k�r�A���N�h���ݦ��S���@�˪��X�k�r
			{
				memset(visited,false,sizeof(visited));
				if(c=='A' || c=='E'||c=='I' || c=='O'||c=='U' || c=='Y')
					vow=1;
				else
					vow=0;
				DFS_B(i,j,0);
			}
		}
	}
	//cout << endl;
}
int main()
{
	string s;
	bool flag=false;
	int i,line=1,col=1;
	set<string>::iterator it;
	while(getline(cin,s))
	{
		if(s=="#")
			break;
		if(s=="")//�M��
		{
			line=1;
			memset(existB,false,sizeof(existB));
			memset(existA,false,sizeof(existA));
			memset(visited,false,sizeof(visited));
			memset(listA,(int)'\0',sizeof(listA));
			memset(listB,(int)'\0',sizeof(listB));
			wordA.clear();
			ans.clear();
		}
		else
		{
			col=1;
			for(i=0;i<7;i=i+2)
			{
				listA[line][col]=s[i];
				listB[line][col++]=s[i+11];
				existB[(s[i+11]-64)]=true;//�NB�����r���s�_��
				
			}
			line++;
			if(line==5)//��J�����A�i��B��
			{
				find_word_inA();
				find_word_inB();
				if(flag)
					printf("\n");
				flag=true;
				if(ans.begin()==ans.end())
					printf("There are no common words for this pair of boggle boards.\n");
				else
				{
					for(it=ans.begin();it!=ans.end();it++)
						cout << *it << endl;
				}
			}
		}
	}
	return 0;
}
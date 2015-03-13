#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define Max 11000
using namespace std;

int p[Max*2],n;//,r[11000];
int FindSet(int x)
{
	if(p[x] == x)
		return x;
	return p[x] = FindSet(p[x]);
}
/*void Union(int x,int y)
{
	x=FindSet(x);
	y=FindSet(y);
	if(x!=y)//��Ӥ��b�P�@��group
	{
		if(r[x]<r[y])
			p[x]=y;
		else//r[x]>=r[y]
		{
			p[y]=x;
			if(r[x]==r[y])
				r[x]++;
		}
	}
}*/
void setFriend(int x,int y)
{
	int px=FindSet(x),py=FindSet(y);//�M��x��y�U��group���ӷ�
	int xe=FindSet(x+n),ye=FindSet(y+n);//�M��x��y�U�۪�enemy
	if(px==ye || py==xe)//�ڪB�ͬO�A�ĤH �� �ڼĤH�O�A�B��
		printf("-1\n");
	else
	{
		p[px]=py;//�A���B�ʹN�O�ڪ��B��
		p[xe]=ye;//�A���ĤH�N�O�ڪ��ĤH
	}
}
void setEnemy(int x,int y)
{
	int px=FindSet(x),py=FindSet(y);//�M��x��y�U��group���ӷ�
	int xe=FindSet(x+n),ye=FindSet(y+n);//�M��x��y�U�۪�enemy
	if(px==py || ye==xe)//�ڪB�ͬO�A�B�� �� �ڼĤH�O�A�ĤH
		printf("-1\n");
	else
	{
		p[px]=ye;//�A���ĤH�N�O�ڪ��B��
		p[py]=xe;//�A���ĤH�N�O�ڪ��B��
	}
}
int main()
{
	int c,x,y,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p[i]=i;
		p[i+n]=i+n;
	}
	while(scanf("%d%d%d",&c,&x,&y)!=EOF)
	{
		if(c==0 && x==0 && y==0)
			break;
		if(c==1)//�P�@��Aroot�O�@�˪� //�p�G�P�e�z����Ĳ ��X-1
		{
			setFriend(x,y);
		}
		else if(c==2)//���P��Aroot���@�� //�p�G�P�e�z����Ĳ ��X-1
		{
			setEnemy(x,y);
		}
		else if(c==3)//�ݬO���O�B�� �O���ܿ�X1 �_���ܿ�X0
		{
			printf("%d\n",(FindSet(x)==FindSet(y))?1:0);
		}
		else//c==4 ��x&y�O���Oenemy �O���ܿ�X1 �_���ܿ�X0
		{
			printf("%d\n",(FindSet(x)==FindSet(y+n))?1:0);//�ڪB�͸�A�ĤH���B�ͤ@�˪��� �ڸ�A�N�O�ĤH
		}
	}
	return 0;
}
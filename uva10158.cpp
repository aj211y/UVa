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
	if(x!=y)//兩個不在同一個group
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
	int px=FindSet(x),py=FindSet(y);//尋找x跟y各自group的來源
	int xe=FindSet(x+n),ye=FindSet(y+n);//尋找x跟y各自的enemy
	if(px==ye || py==xe)//我朋友是你敵人 或 我敵人是你朋友
		printf("-1\n");
	else
	{
		p[px]=py;//你的朋友就是我的朋友
		p[xe]=ye;//你的敵人就是我的敵人
	}
}
void setEnemy(int x,int y)
{
	int px=FindSet(x),py=FindSet(y);//尋找x跟y各自group的來源
	int xe=FindSet(x+n),ye=FindSet(y+n);//尋找x跟y各自的enemy
	if(px==py || ye==xe)//我朋友是你朋友 或 我敵人是你敵人
		printf("-1\n");
	else
	{
		p[px]=ye;//你的敵人就是我的朋友
		p[py]=xe;//你的敵人就是我的朋友
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
		if(c==1)//同一國，root是一樣的 //如果與前述有牴觸 輸出-1
		{
			setFriend(x,y);
		}
		else if(c==2)//不同國，root不一樣 //如果與前述有牴觸 輸出-1
		{
			setEnemy(x,y);
		}
		else if(c==3)//看是不是朋友 是的話輸出1 否的話輸出0
		{
			printf("%d\n",(FindSet(x)==FindSet(y))?1:0);
		}
		else//c==4 看x&y是不是enemy 是的話輸出1 否的話輸出0
		{
			printf("%d\n",(FindSet(x)==FindSet(y+n))?1:0);//我朋友跟你敵人的朋友一樣的話 我跟你就是敵人
		}
	}
	return 0;
}
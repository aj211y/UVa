//任兩點間至少需有一條路徑聯通(直接或非直接)
//P個點 至少需要有P-1條邊 
/*
	有S個衛星 衛星通訊代表兩點都有衛星 才能形成衛星通訊
	**從同一頂點直線連過去的話**
	=>若有S個衛星 則能形成 S-1 條邊
	題目給定P個頂點 會有P-1條邊
	又已知有S個衛星 也就是存在S-1條權重為零的邊
	所以只需要再拿(P-1)-(S-1)=>P-S條邊即可
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int p[510],c,r[510];
struct point
{
	double x,y;
}star[510];
struct node
{
	int start,end;
	double len;
}list[250050];
bool cmp(node a,node b)
{
	return a.len<b.len?true:false;
}
int FindSet(int x)
{
	return p[x]==x?x:p[x]=FindSet(p[x]);
}
void Union(int x,int y)
{
	x=FindSet(x);
	y=FindSet(y);
	if(x!=y)//不同group
	{
		if(r[x]<r[y])
			p[x]=y;
		else//r[x]>=r[y]
		{
			p[y]=x;
			if(r[x]==r[y])
				r[x]++;
		}
		c++;
	}
}
int main()
{
	int test,S,P,i,j,edge;
	double ans;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&S,&P);
		for(i=1;i<=P;i++)
			scanf("%lf%lf",&star[i].x,&star[i].y);
		edge=0;
		for(i=1;i<=P;i++)
		{
			for(j=i+1;j<=P;j++)
			{
				list[edge].start=i;
				list[edge].end=j;
				list[edge++].len=sqrt(pow(star[i].x-star[j].x,2)+pow(star[i].y-star[j].y,2));
				//printf("%lf\n",list[edge-1].len);
			}
		}
		sort(list,list+edge,cmp);
		for(i=1;i<=P;i++)
		{
			p[i]=i;
			r[i]=1;
		}
		c=0;//數現在選入幾條邊了
		//kruscal
		for(i=0;i<edge;i++)//只需P-S條
		{
			Union(list[i].start,list[i].end);
			//printf("c-%d\nlen-%lf\n",c,list[i].len);
			if(c==P-S)
			{
				ans=list[i].len;
				break;
			}
		}
		printf("%.2lf\n",ans);
		
		//list.clear();
	}
	return 0;
}
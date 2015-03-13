//�����I���ܤֻݦ��@�����|�p�q(�����ΫD����)
//P���I �ܤֻݭn��P-1���� 
/*
	��S�ӽìP �ìP�q�T�N����I�����ìP �~��Φ��ìP�q�T
	**�q�P�@���I���u�s�L�h����**
	=>�Y��S�ӽìP �h��Φ� S-1 ����
	�D�ص��wP�ӳ��I �|��P-1����
	�S�w����S�ӽìP �]�N�O�s�bS-1���v�����s����
	�ҥH�u�ݭn�A��(P-1)-(S-1)=>P-S����Y�i
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
	if(x!=y)//���Pgroup
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
		c=0;//�Ʋ{�b��J�X����F
		//kruscal
		for(i=0;i<edge;i++)//�u��P-S��
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
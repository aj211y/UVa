#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<algorithm>
#define Max 1010
using namespace std;

int p[Max];
struct node
{
	int start,end;
	int len;
}list[25100];
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
	if(x!=y)
	{
		p[x]=y;
	}
}
int main()
{
	int n,m,a,b,len,edge,i;
	bool flag,space;
	vector<int> ans;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0)
			break;
		for(i=0;i<Max;i++)
			p[i]=i;
		edge=0;
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&a,&b,&len);
			list[edge].start=a;
			list[edge].end=b;
			list[edge++].len=len;
		}
		sort(list,list+edge,cmp);
		flag=false;
		for(i=0;i<edge;i++)
		{
			if(FindSet(list[i].start)!=FindSet(list[i].end))
			{
				Union(list[i].start,list[i].end);
			}
			else
			{
				flag=true;
				ans.push_back(list[i].len);
			}
		}
		space=false;
		if(flag)
		{
			for(i=0;i<ans.size();i++)
			{
				if(space)
					printf(" ");
				space=true;
				printf("%d",ans[i]);
			}
			printf("\n");
		}
		else
			printf("forest\n");
		ans.clear();
	}
	return 0;
}
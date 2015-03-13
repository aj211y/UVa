#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<map>
#include<set>
#include<algorithm>
#define Max 200010
using namespace std;

int p[Max],num[Max];
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
		p[x]=y;//將p[x]更新為y，之後找group數就會找到num[y]，所以修正num[y]即可
		num[y]+=num[x];//更新y的朋友數
	}
}
int main()
{
	string Fa,Fb;
	map<string,int> dic;
	set<string> exist;
	int test,F,i,id,j,ans;
	while(scanf("%d",&test)!=EOF)
	{
		while(test--)
		{
			scanf("%d",&F);
			for(i=1;i<=2*F;i++)
			{
				p[i]=i;
				num[i]=1;
			}
			id=1;
			for(i=1;i<=F;i++)
			{
				cin>>Fa>>Fb;
				if(exist.find(Fa)==exist.end())//新人
				{
					exist.insert(Fa);
					dic[Fa]=id++;
				}
				if(exist.find(Fb)==exist.end())//新人
				{
					exist.insert(Fb);
					dic[Fb]=id++;
				}
				Union(dic[Fa],dic[Fb]);
				ans=FindSet(dic[Fa]);
				printf("%d\n",num[ans]);
			}
			exist.clear();
			dic.clear();
		}
	}
	return 0;
}
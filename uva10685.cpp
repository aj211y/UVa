#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

int p[5100],r[5100];
int FindSet(int x)
{
	return p[x]==x?x:p[x]=FindSet(p[x]);
}
void Union(int x,int y)
{
	x=FindSet(x);
	y=FindSet(y);
	if(x!=y)//not in the same group
	{
		if(r[x]<r[y])
		{
			p[y]=x;
		}
		else//r[x]>=r[y]
		{
			p[y]=x;
			if(r[x]==r[y])
				r[x]++;
		}
	}
}
int main()
{
	int C,R,i,id[5100],Max,j;
	string str,name,tmp;
	map<string,int> dic;
	while(scanf("%d%d",&C,&R)!=EOF)
	{
		if(C==0 && R==0)
			break;
		for(i=1;i<=C;i++)//CºØ°Êª«
		{
			cin>>name;
			dic[name]=i;
			p[i]=i;
			r[i]=1;
		}
		getchar();
		for(i=1;i<=R;i++)
		{
			getline(cin,str);
			//cout << i<< str <<endl;
			name="";
			for(j=0;j<str.size();j++)
			{
				if(str[j]==' ')
				{
					tmp=name;
					name="";
					continue;
				}
				name+=str[j];
			}
			Union(dic[name],dic[tmp]);
		}
		memset(id,0,sizeof(id));
		Max=0;
		for(i=1;i<=C;i++)
		{
			id[FindSet(i)]++;
			if(Max<id[FindSet(i)])
				Max=id[FindSet(i)];
		}
		printf("%d\n",Max);
	}
	return 0;
}
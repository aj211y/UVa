#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#define Max 1000000
using namespace std;

map<string,int> country;//國家轉數字
set<string> weman[Max];//記錄每個國家出現的女人
int num[Max],id=0;//記錄這個國家有幾個女人出現
struct node
{
	string c;
	int num;
}list[Max];
bool cmp(node a,node b)
{
	if(a.c<b.c)
		return true;
	else
		return false;
}
int main()
{
	string coun,name,str;
	map<string,int>::iterator it;
	memset(num,0,sizeof(num));
	int n,i;
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		coun="";
		name="";
		getline(cin,str);
		for(i=0;i<str.size();i++)
		{	
			if(str[i]==' ')
				break;
			coun+=str[i];
		}
		for(;i<str.size();i++)
			name+=str[i];
		if(country.find(coun)==country.end())//找不到==新國家
			country[coun]=id++;
		if(weman[country[coun]].find(name)==weman[country[coun]].end())
		{
			weman[country[coun]].insert(name);
			num[country[coun]]++;
		}
	}
	for(it=country.begin(),i=0;it!=country.end();it++,i++)
	{
		list[i].c=it->first;
		list[i].num=num[it->second];
	}
	sort(list,list+id,cmp);
	for(i=0;i<id;i++)
		cout << list[i].c <<" "<<list[i].num << endl;
	return 0;
}
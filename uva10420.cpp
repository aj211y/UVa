#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#define Max 1000000
using namespace std;

map<string,int> country;//��a��Ʀr
set<string> weman[Max];//�O���C�Ӱ�a�X�{���k�H
int num[Max],id=0;//�O���o�Ӱ�a���X�Ӥk�H�X�{
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
		if(country.find(coun)==country.end())//�䤣��==�s��a
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
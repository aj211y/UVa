#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<vector>
#include<set>
using namespace std;

struct node
{
	string ori,tmp;
	bool flag;
};
vector<node> list;
int main()
{
	int i,len,j;
	node data;
	set<string> ans;
	set<string>::iterator it;
	while(cin >> data.ori &&data.ori!="#")
	{
		data.tmp=data.ori;
		data.flag=true;
		len=data.ori.size();
		for(i=0;i<len;i++)
			data.tmp[i]=tolower(data.tmp[i]);
		sort(data.tmp.begin(),data.tmp.end());
		list.push_back(data);
	}
	for(i=0;i<list.size();i++)
	{
		//cout << list[i].tmp << endl;
		if(list[i].flag)
		{
			for(j=i+1;j<list.size();j++)
			{
				
				if(list[i].tmp==list[j].tmp)
				{
					//cout << list[i].tmp << endl;
					list[i].flag=false;
					list[j].flag=false;
				}
			}
		}
	}
	for(i=0;i<list.size();i++)
	{
		if(list[i].flag)
			ans.insert(list[i].ori);
	}
	for(it=ans.begin();it!=ans.end();it++)
		cout << *it << endl;
	return 0;
}
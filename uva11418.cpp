#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cctype>
#include<vector>
#include<set>
#include<cstring>
using namespace std;

bool cmp(string a,string b)
{
	if(a<b)
		return true;
	else
		return false;
}
bool cmpsize(vector<string> a,vector<string> b)
{
	if(a.size()<b.size())
		return true;
	else
		return false;
}
int main()
{	
	int N,test=1,n,k,i,s;
	string str;
	vector<string> list[30];
	set<string> ans;
	set<char> check;
	set<string> :: iterator it;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&k);
			while(k--)
			{
				cin >> str;
				str[0]=toupper(str[0]);
				for(s=1;s<str.size();s++)
					str[s]=tolower(str[s]);
				list[i].push_back(str);				
			}
			sort(list[i].begin(),list[i].end(),cmp);
		}
		sort(&list[0],&list[n],cmpsize);
		for(i=0;i<n;i++)
		{
			for(k=0;k<list[i].size();k++)
			{
				if(check.find(list[i][k][0])==check.end())
				{
					ans.insert(list[i][k]);
					check.insert(list[i][k][0]);
					break;
				}
			}
		}
		printf("Case #%d:\n",test++);
		for(it=ans.begin();it!=ans.end();it++)
			cout << *it << endl;
		for(i=0;i<n;i++)
			list[i].clear();
		ans.clear();
		check.clear();
		
	}
	return 0;
}
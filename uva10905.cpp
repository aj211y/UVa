#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;

string list[60];
bool cmp(string a,string b)
{
	string t1=a+b,t2=b+a;
	if(t1>t2)
		return true;
	else
		return false;
}
int main()
{
	int N,i;
	while(scanf("%d",&N)&&N!=0)
	{
		//memset(list,'/0',sizeof(list));
		for(i=0;i<N;i++)
			cin>>list[i];
		sort(list,list+N,cmp);
		for(i=0;i<N;i++)
			cout<<list[i];
		cout<<endl;
	}
	return 0;
}
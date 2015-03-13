#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;

string str,tmp;
char data[20];
bool choose[20];
set<string> ans;
set<string>::iterator it;
int str_len;	
void backtrack(int len)
{
	int i;
	if(len==str_len)//已經填完了
	{
		tmp=data;
		ans.insert(tmp);
	}
	else//還沒有填完
	{
		for(i=0;i<str_len;i++)
		{
			if(!choose[i])//還沒被選過
			{
				choose[i]=true;//選你~~
				data[len]=str[i];//存起來
				backtrack(len+1);//再跑backtrack繼續排
				choose[i]=false;//不選了換別人排這裡看看
			}
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		memset(choose,false,sizeof(choose));
		memset(data,(int)'\0',sizeof(data));
		cin >> str;
		str_len=str.size();
		backtrack(0);//一開始都還沒有填所以長度為零
		for(it=ans.begin();it!=ans.end();it++)
			cout << *it << endl;
		cout << endl;
		ans.clear();
	}
	return 0;
}
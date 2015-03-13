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
	if(len==str_len)//�w�g�񧹤F
	{
		tmp=data;
		ans.insert(tmp);
	}
	else//�٨S����
	{
		for(i=0;i<str_len;i++)
		{
			if(!choose[i])//�٨S�Q��L
			{
				choose[i]=true;//��A~~
				data[len]=str[i];//�s�_��
				backtrack(len+1);//�A�]backtrack�~���
				choose[i]=false;//����F���O�H�Ƴo�̬ݬ�
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
		backtrack(0);//�@�}�l���٨S����ҥH���׬��s
		for(it=ans.begin();it!=ans.end();it++)
			cout << *it << endl;
		cout << endl;
		ans.clear();
	}
	return 0;
}
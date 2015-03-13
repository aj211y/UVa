#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;

int oder[10],list[150],n,code[10],a;
string ans;
void decode()
{
	int i,front,back;
	front=1;
	back=pow(2,n);
	for(i=0;i<n;i++)
	{
		if(code[oder[i]]==0)
			back=(front+back-1)/2;
		else
			front=(front+back-1)/2+1;
	}
	ans[a++]=list[front];
}
int main()
{
	int m,i,j,len,test=1;
	string str;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		memset(oder,0,sizeof(oder));
		memset(list,0,sizeof(list));
		getchar();
		getline(cin,str);
		for(i=1,j=0;i<str.size();i=i+3,j++)
			oder[j]=str[i]-48;
		getline(cin,str);
		for(i=1,j=0;j<str.size();i++,j++)
			list[i]=str[j]-48;
		scanf("%d",&m);
		getchar();
		a=0;
		for(i=0;i<m;i++)
		{
			getline(cin,str);
			for(j=0;j<str.size();j++)
				code[j+1]=str[j]-48;
			decode();
		}
		printf("S-Tree #%d:\n",test++);
		for(i=0;i<a;i++)
			printf("%d",ans[i]);
		printf("\n\n");
	}
	return 0;
}
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;

bool exist[30],visited[30];
int degree[30],list[30][30],num;
char tmp[30],dic[28]={'\0','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'};
set<string> ans;
set<string>::iterator it;
void DFS(int id,int len)
{
	int i;
	tmp[len]=dic[id];
	visited[id]=true;
	//printf("id-%d\n",id);
	if(len==num-1)
	{
		//cout << tmp << endl;
		ans.insert((string)tmp);
	}
	else
	{
		
		for(i=1;i<27;i++)
		{
			if(exist[i] && list[id][i])
			{
				degree[i]--;
				//printf("i-%d degree-%d\n",i,degree[i]);
			}
		}
		for(i=1;i<27;i++)
		{
			if(exist[i] &&(degree[i]==0)&& !visited[i])
			{
				visited[i]=true;
				DFS(i,len+1);
				visited[i]=false;
			}
		}
		for(i=1;i<27;i++)
		{
			if(exist[i] && list[id][i])
			{
				degree[i]++;
				//printf("i-%d degree-%d\n",i,degree[i]);
			}
		}
	}
	visited[id]=false;
}
int main()
{
	int test,i;
	string line,str;
	bool flag,second=false;
	scanf("%d",&test);
	getchar();

	while(test--)
	{
		if(second)
			printf("\n");
		second=true;
		getchar();
		memset(exist,false,sizeof(exist));
		memset(degree,0,sizeof(degree));
		memset(list,0,sizeof(list));
		memset(visited,true,sizeof(visited));
		getline(cin,line);
		num=0;
		for(i=0;i<line.size();i=i+2)
		{
			exist[line[i]-64]=true;
			visited[line[i]-64]=false;
			num++;//共有幾個字母
		}
		//cout << "num-" <<num << endl;
		getline(cin,line);
		for(i=0;i<line.size();i=i+4)
		{
			list[line[i]-64][line[i+2]-64]=1;
			degree[line[i+2]-64]++;
		}
		for(i=1;i<27;i++)
		{
			if(exist[i]&&degree[i]==0)
			{
				memset(tmp,(int)'\0',sizeof(tmp));
				DFS(i,0);
			}
		}
		if(ans.empty())
		{
			printf("NO\n");
		}
		else
		{
			for(it=ans.begin();it!=ans.end();it++)
			{
				str=*it;
				flag=false;
				for(i=0;i<str.size();i++)
				{
					if(flag)
						printf(" ");
					flag=true;
					printf("%c",str[i]);
				}
				printf("\n");
			}
		}
		ans.clear();
	}
	return 0;
}
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int llink[260],rlink[260];
char Left[260];
bool used[260];
vector<int> list[260];
bool DFS(int now)
{
	int i,next;
	for(i=0;i<list[now].size();i++)
	{
		next=list[now][i];
		if(!used[next])
		{
			used[next]=true;
			if(!rlink[next] || DFS(rlink[next]))
			{
				llink[now]=next;
				rlink[next]=now;
				return true;
			}
		}
	}
	return false;
}
int bipartite(int L)
{
	int i,ret=0;
	memset(llink,0,sizeof(llink));
	memset(rlink,0,sizeof(rlink));
	
	for(i=1;i<L;i++)
	{
		memset(used,0,sizeof(used));
		if(DFS(i))
			ret++;
	}
	return ret;
}
int main()
{
	int i,num=1,j,ans;
	string line;
	while(getline(cin,line))
	{
		if(line=="")//這個case結束了
		{
			ans=bipartite(num);
			if(ans==num-1)
			{
				for(i=1;i<=10;i++)
				{
					if(rlink[i]==0)
						printf("_");
					else
						printf("%c",Left[rlink[i]]);
				}
				printf("\n");
			}
			else
				printf("!\n");
			memset(Left,'\0',sizeof(Left));
			for(i=0;i<260;i++)
				list[i].clear();
			num=1;
		}
		else
		{		
			for(i=0;i<line[1]-48;i++)//line[1]-48為有幾個這類型的job
			{
				Left[num]=line[0];
				for(j=3;j<line.size()-1;j++)
					list[num].push_back(line[j]-47);
				num++;
			}
		}
	}
	ans=bipartite(num);
	if(ans==num-1)
	{
		for(i=1;i<=10;i++)
		{
			if(rlink[i]==0)
				printf("_");
			else
				printf("%c",Left[rlink[i]]);
		}
		printf("\n");
	}
	else
		printf("!\n");
	return 0;
}
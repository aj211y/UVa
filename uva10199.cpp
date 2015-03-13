#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<algorithm>
#define Max 120
using namespace std;

map<string,int> dic;
map<int,string> dic2;
vector<int> list[Max];
vector<string> ans;
int dfn[Max],low[Max],dfn_count;
void DFS(int now,int pa)
{
	int i,next;
	int child=0;
	bool flag=false;
	dfn[now]=low[now]=dfn_count++;
	//printf("dfn-%d\n",dfn[now]);
	for(i=0;i<list[now].size();i++)
	{
		next=list[now][i];
		//printf("next-%d\n",next);
		if(!dfn[next])
		{
			child++;
			DFS(next,now);
			low[now]=min(low[now],low[next]);
			//printf("dfn-%d low-%d\n",dfn[now],low[now]);
			if(low[next]>=dfn[now])
				flag=true;
		}
		else if(next!=pa)
		{
			low[now]=min(low[now],dfn[next]);
			//printf("next!=pa dfn-%d low-%d\n",dfn[now],low[now]);
		}
	}
	if((child>=2 || pa>0)&&flag)
		ans.push_back(dic2[now]);
}
int main()
{
	int N,i,R,test=1;
	string name,name2;
	bool space=false;
	while(scanf("%d",&N)!=EOF)
	{
		if(N==0)
			break;
		if(space)
			printf("\n");
		space=true;
		//memset(list,0,sizeof(list));
		for(i=0;i<Max;i++)
			list[i].clear();
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		dic.clear();
		dic2.clear();
		ans.clear();
		for(i=1;i<=N;i++)
		{
			cin >> name;
			dic[name]=i;
			dic2[i]=name;
		}
		scanf("%d",&R);
		for(i=0;i<R;i++)
		{
			cin >> name >> name2;
			list[dic[name]].push_back(dic[name2]);
			list[dic[name2]].push_back(dic[name]);
		}
		dfn_count=1;
		for(i=1;i<=N;i++)
		{
			if(!dfn[i])
				DFS(i,0);
		}
		sort(ans.begin(),ans.end());
		printf("City map #%d: %d camera(s) found\n",test++,ans.size());
		for(i=0;i<ans.size();i++)
		{
			cout << ans[i] << endl;
		}
		
	}
	return 0;
}
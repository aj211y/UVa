#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int visited[205]={0};
vector<int> spot[205];
bool flag=false;

void dfs(int a,int b)
{
	int i,next;
	if(visited[b]==1)//塗什麼色
		visited[a]=2;
	else
		visited[a]=1;
	for(i=0;i<spot[a].size();i++){
		next=spot[a][i];
		if(!visited[next])
			dfs(next,a);
		else{
			if(visited[a]==visited[b])
				flag=true;//有錯誤了
		}
	}
}
int main()
{
	int n,line,s1,s2,i;
	while(scanf("%d",&n)!=EOF){
		flag=false;
		if(!n)
			break;
		scanf("%d",&line);
		while(line--){
			scanf("%d%d",&s1,&s2);
			spot[s1].push_back(s2);
			spot[s2].push_back(s1);
		}
		dfs(s1,s2);
		if(flag)
			printf("NOT BICOLORABLE.\n");
		else
			printf("BICOLORABLE.\n");
		for(i=0;i<205;i++){
			spot[i].clear();
			visited[i]=0;
		}
	}
	return 0;
}
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

struct ele
{
	int id,w,s;
};
int smarter[1100][1100];
int dp[1100],path[1100];
bool cmp(const ele&a,const ele&b)
{
	if(a.w<b.w)
		return true;
	else
		return false;
}
int main()
{
	int i,j,ans,ansi;
	ele phant;
	vector<ele> line;
	phant.id=1;
	while(scanf("%d%d",&phant.w,&phant.s)!=EOF){
		line.push_back(phant);
		phant.id++;
	}
	memset(smarter,0,sizeof(smarter));
	sort(line.begin(),line.end(),cmp);
	for(i=0;i<line.size();i++){
		dp[i]=1;
		path[i]=i;
	}
	for(j=1;j<line.size();j++){
		for(i=0;i<j;i++){
			if(line[i].s>line[j].s && line[i].w < line[j].w){
				smarter[i][j]=1;
			}
		}
	}
	ans=ansi=1;
	for(j=1;j<line.size();j++){
		for(i=0;i<j;i++){
			if(smarter[i][j]&&dp[j]<dp[i]+1){
				dp[j]=dp[i]+1;
				path[j]=i;
			}
		}
		if(dp[j]>ans){
			ans=dp[j];
			ansi=i;
		}
	}
	printf("%d\n",ans);
	for(i=ansi,j=0;;j++){
		dp[j]=line[i].id;
		if(path[i]==i)
			break;
		else
			i=path[i];
	}
	for(i=j;i>=0;i--){
		printf("%d\n",dp[i]);
	}
	return 0;
}
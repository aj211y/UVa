#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<queue>
#define MAX 1000000
using namespace std;

struct node
{
	int id,road;
};
vector<node> list[120];
int dp[120];
bool inqueue[120];
int main()
{
	queue<int> wait;
	int N,R,i,c1,c2,S,D,T,w,test=1,ans,m;
	node data;
	while(scanf("%d%d",&N,&R)&&(N|R)){
		for(i=0;i<R;i++){
			scanf("%d%d%d",&c1,&c2,&data.road);
			data.road--;
			data.id=c1;
			list[c2].push_back(data);
			data.id=c2;
			list[c1].push_back(data);
		}
		scanf("%d%d%d",&S,&D,&T);
		memset(inqueue,false,sizeof(inqueue));
		memset(dp,0,sizeof(dp));
		dp[S]=MAX;
		wait.push(S);
		inqueue[S]=inqueue[D]=true;
		while(!wait.empty()){
			w=wait.front();
			wait.pop();
			if(w!=S)
				inqueue[w]=false;
			for(i=0;i<list[w].size();i++){
				//printf("w-%d d-%d r-%d\n",w,list[w][i].id,list[w][i].road);
				m=min(dp[w],list[w][i].road);
				if(m>dp[list[w][i].id]){
					if(!inqueue[list[w][i].id]){
						wait.push(list[w][i].id);
						inqueue[list[w][i].id]=true;
					}
					dp[list[w][i].id]=m;
				}
				//printf("dp[%d]-%d\n",list[w][i].id,dp[list[w][i].id]);
				
			}
		}
		//printf("%d\n",dp[D]);
		ans=ceil((float)T/dp[D]);
		printf("Scenario #%d\nMinimum Number of Trips = %d\n\n",test++,ans);
		for(i=0;i<120;i++){
			list[i].clear();
		}
	}
	return 0;
}
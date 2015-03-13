#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#include<stack>
#define MAX 50000
using namespace std;

struct node
{
	int des,cost;
};
vector<node> line[15];
int pre[15];
int dis[15];
bool visited[15];
int main()
{
	node d;
	queue<int> loc;
	stack<int> ans;
	int spot,i,num,j,s,e,f,number=1;
	while(scanf("%d",&spot)&&spot){
		for(i=1;i<=spot;i++){
			scanf("%d",&num);
			line[i].push_back(d);
			while(num--){
				scanf("%d%d",&d.des,&d.cost);
				line[i].push_back(d);
			}
		}
		scanf("%d%d",&s,&e);
		memset(pre,0,sizeof(pre));
		memset(visited,false,sizeof(visited));
		for(i=0;i<15;i++)
			dis[i]=MAX;
		dis[s]=0;
		visited[s]=true;
		loc.push(s);
		while(!loc.empty()){
			f=loc.front();
			loc.pop();
			visited[f]=false;//不在queue裡面
			for(i=1;i<line[f].size();i++){
				j=line[f][i].des;
				if(line[f][i].cost+dis[f]<dis[j]){//如果可以被更新
					dis[j]=line[f][i].cost+dis[f];//就更新啊
					pre[j]=f;//記錄從哪一點來的
					if(!visited[j]) {//被更新的時候不在queue裡面
						loc.push(j);//就要push進去，因為他被更新過了，所以他可以連動到的地方都要跑過一次(若在queue裡面，就表示等一下就會更新，所以不用再放進去一次)
						visited[j] = true;
					}
				}
			}
		}
		i=e;
		ans.push(e);
		while(pre[i]){
			ans.push(pre[i]);
			i=pre[i];
		}
		//ans.push(s);
		
		printf("Case %d: Path =",number++);
		while(!ans.empty()){
			printf(" %d",ans.top());
			ans.pop();
		}
		printf("; %d second delay\n",dis[e]);
		for(i=0;i<15;i++){
			line[i].clear();
		}
	}
	return 0;
}

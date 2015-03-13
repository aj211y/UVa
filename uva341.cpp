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
			visited[f]=false;//���bqueue�̭�
			for(i=1;i<line[f].size();i++){
				j=line[f][i].des;
				if(line[f][i].cost+dis[f]<dis[j]){//�p�G�i�H�Q��s
					dis[j]=line[f][i].cost+dis[f];//�N��s��
					pre[j]=f;//�O���q���@�I�Ӫ�
					if(!visited[j]) {//�Q��s���ɭԤ��bqueue�̭�
						loc.push(j);//�N�npush�i�h�A�]���L�Q��s�L�F�A�ҥH�L�i�H�s�ʨ쪺�a�賣�n�]�L�@��(�Y�bqueue�̭��A�N��ܵ��@�U�N�|��s�A�ҥH���ΦA��i�h�@��)
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

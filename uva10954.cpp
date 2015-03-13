#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

struct NODE
{
	int v;
	bool operator < (const NODE & in) const{
		return v> in.v;
	}
};
int main()
{
	int n,sum;
	priority_queue<NODE> pq;
	NODE tmp;
	while(scanf("%d",&n)&&n){
		sum=0;
		while(n--){
			scanf("%d",&tmp.v);
			pq.push(tmp);//這樣就會幫你排序喔
		}
		while(!pq.empty()){
			tmp=pq.top();
			pq.pop();
			if(!pq.empty()){
				tmp.v+=pq.top().v;
				pq.pop();
				sum+=tmp.v;
				pq.push(tmp);
			}
			else
				break;
		}
		printf("%d\n",sum);
	}
	return 0;
}
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

int path[100000];
int main()
{
	int i,d,k=0;
	vector<int> line,tmp;
	stack<int> ans;
	while(scanf("%d",&d)!=EOF)
		line.push_back(d);
	tmp.push_back(line[0]);
	path[0]=tmp.size();
	for(i=1;i<line.size();i++){
		if(line[i]>tmp.back()){
			tmp.push_back(line[i]);
			path[i]=tmp.size();
		}
		else{
			*lower_bound(tmp.begin(),tmp.end(),line[i])=line[i];
			path[i]=lower_bound(tmp.begin(),tmp.end(),line[i])-tmp.begin()+1;
		}
	}
	printf("%d\n-\n",tmp.size());
	for(i=line.size()-1;i>=0;i--){
		if(tmp.size()==path[i]){
			ans.push(line[i]);
			tmp.pop_back();
		}
		if(tmp.empty())
			break;
	}
	while(!ans.empty()){
		printf("%d\n",ans.top());
		ans.pop();
	}
	return 0;
}
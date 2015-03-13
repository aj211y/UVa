#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct node
{
	int id;
	int p;
};
vector<node> list;
bool cmp(const node& a,const node& b)
{
	if(a.id<b.id)
		return true;
	else 
		return false; 
}
bool cmp2(const node& a,const node& b)
{
	if(a.p>b.p)
		return true;
	else 
		return false; 
}
void func(int t)
{
	int i,j;
	vector<node> tmp;
	for(i=1;i<list.size();i++){
		for(j=0;j<i;j++){
			if(list[i].id<list[j].id)
				tmp.push_back(list[j]);
		}
		if(!tmp.empty()){
			sort(tmp.begin(),tmp.end(),cmp2);
			list[i].p=tmp[0].p+1;
		}
		tmp.clear();
	}
	sort(list.begin(),list.end(),cmp2);
	if(t!=1)
		printf("\n");
	printf("Test #%d:\n",t);
	printf("  maximum possible interceptions: %d\n",list[0].p);
	list.clear();
}
int main()
{
	int T=1;
	node d;
	bool flag=false;
	while(scanf("%d",&d.id)!=EOF){
		if(flag && d.id<0)
			break;
		flag=false;
		d.p=1;
		if(d.id<0){
			flag=true;
			func(T++);
		}
		else
			list.push_back(d);
	}
	return 0;
}
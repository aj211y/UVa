#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
using namespace std;
vector<long long int> list;

int canbe(long long int a)
{
	long long int i,sum=0;
	int div=1;
	for(i=list.size()-1;i>=0;i--){
		if((sum+list[i])>a){
			div++;
			sum=list[i];
		}
		else
			sum+=list[i];
	}
	return div;//回傳分成幾團
}
int main()
{
	int test,m,k,i;
	long long int max,sum,beg,end,mid,data;
	stack<long long int> ans;
	scanf("%d",&test);
	while(test--){
		scanf("%d%d",&m,&k);
		max=0;
		sum=0;
		while(m--){
			scanf("%lld",&data);
			if(data>max)
				max=data;
			sum+=data;
			list.push_back(data);
		}
		beg=max;
		end=sum;
		while(beg<end){
			mid=(beg+end)/2;
			if(canbe(mid)>k)
				beg=mid+1;
			else
				end=mid;
		}
		sum=0;
		k--;
		for(i=list.size()-1;i>=0;i--){
			if((sum+list[i])>beg && i+1>=k || i+1==k){ //剩餘個數要大於剩餘須分幾團
				sum=list[i];
				ans.push(0);
				k--;
			}
			else{
				sum+=list[i];
			}
			ans.push(list[i]);
		}
		while(!ans.empty()){
			if(ans.top()==0)
				printf("/");
			else
				printf("%lld",ans.top());
			ans.pop();
			if(!ans.empty())
				printf(" ");
		}
		printf("\n");
		list.clear();
	}
	return 0;
}
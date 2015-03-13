#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

struct wine
{
	long long int bot,loc;
};
int main()
{
	int n,i,j,tmp;
	long long int d,sum;
	wine data;
	vector<wine> buy,sell;
	while(scanf("%d",&n)!=EOF){
		if(!n)
			break;
		tmp=n;
		while(tmp--){
			scanf("%lld",&d);
			data.loc=n-tmp;
			if(d<0){
				data.bot=-d;
				sell.push_back(data);
			}
			else{
				data.bot=d;
				buy.push_back(data);
			}
		}
		i=j=0;
		sum=0;
		do{
			if(sell[i].bot > buy[j].bot){
				sum+=buy[j].bot*abs(buy[j].loc-sell[i].loc);
				sell[i].bot=sell[i].bot-buy[j].bot;
				buy[j].bot=0;
			}
			else{
				sum+=sell[i].bot*abs(buy[j].loc-sell[i].loc);
				buy[j].bot=buy[j].bot-sell[i].bot;
				sell[i].bot=0;
			}
			if(buy[j].bot==0)
				j++;
			if(sell[i].bot==0)
				i++;
		}while(i<sell.size()&&j<buy.size());
		printf("%lld\n",sum);
		buy.clear();
		sell.clear();
		
	}
	return 0;
}
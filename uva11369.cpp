#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int t,item;
	long long int data,i,sum;
	vector<long long int> price;
	scanf("%d",&t);
	while(t--){
		sum=0;
		scanf("%d",&item);
		while(item--){
			scanf("%lld",&data);
			price.push_back(data);
		}
		sort(price.begin(),price.end());
		for(i=price.size()%3;i<price.size();i=i+3)
			sum+=price[i];
		printf("%lld\n",sum);
		price.clear();
	}
	return 0;
}
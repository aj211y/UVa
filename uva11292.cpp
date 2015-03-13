#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n,m,data,i,sum,j;
	vector<int> head,knight;
	while(scanf("%d%d",&n,&m) && (n|m)){
		while(n--){
			scanf("%d",&data);
			head.push_back(data);
		}
		while(m--){
			scanf("%d",&data);
			knight.push_back(data);
		}
		sort(head.begin(),head.end());
		sort(knight.begin(),knight.end());
		sum=0;
		for(i=0,j=0;i<head.size();i++){
			while(knight[j]<head[i] && j<knight.size())
				j++;
			if(j < knight.size())
				sum+=knight[j++];
			else
				break;
		}
		if(i<head.size())
			printf("Loowater is doomed!\n");
		else
			printf("%d\n",sum);
		head.clear();
		knight.clear();
	}
	return 0;
}
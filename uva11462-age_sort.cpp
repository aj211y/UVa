//uva11462 ¦~ÄÖ±Æ§Ç
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;

int main()
{
	int people,x;
	int count;
	vector<int> age;
	while(scanf("%d",&people)!=EOF){
		if(!people)
			break;
		count=people;
		while(count--){
			scanf("%d",&x);
			age.push_back(x);
		}
		sort(age.begin(),age.end());
		for(x=0;x<age.size();x++){
			printf("%d",age[x]);
			if(x==age.size()-1)
				printf("\n");
			else
				printf(" ");
		}
		age.clear();
	}
	return 0;
}
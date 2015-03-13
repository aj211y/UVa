#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int i,count,line,sum;
	string str;
	vector<int> num;
	while(scanf("%d",&line)!=EOF){
		if(!line)
			break;
		sum=0;
		getchar();
		while(line--){
			count=0;
			getline(cin,str);
			for(i=0;i<25;i++){
				if(str[i]==' ')
					count++;
			}
			num.push_back(count);
			sum=sum+count;
		}
		sort(num.begin(),num.end());
		printf("%d\n",sum-num.size()*num[0]);
		num.clear();
	}
	return 0;
}
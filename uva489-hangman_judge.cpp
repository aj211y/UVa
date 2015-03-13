//abc 猜測為defghijabc的話是lose 猜測為abdefghicj的話為win
#include<iostream>
#include<cstdio>
#include<set>
#include<string>
#include<queue>
using namespace std;

int main()
{	
	bool flag;
	int round,i,count;
	string str;
	set<char> ques,ans;
	set<char>::iterator it;
	while(scanf("%d",&round)!=EOF){
		if(round<0)
			break;
		count=0;
		flag=0;
		cin >> str;
		for(i=0;i<str.size();i++)
			ques.insert(str[i]);
		cin >> str;
		for(i=0;i<str.size();i++){
			if(ques.find(str[i])==ques.end()&&ans.find(str[i])==ans.end())//s當中沒有此符號，在之前也沒有猜過
				count++;
			else if(ques.find(str[i])!=ques.end())
				ques.erase(str[i]);
			ans.insert(str[i]);
			if(count==7||ques.empty())
				break;
		}
		printf("Round %d\n",round);
		if(count>=7)
			printf("You lose.\n");
		else{
			if(!ques.empty())
				printf("You chickened out.\n");
			else
				printf("You win.\n");
		}
		ques.clear();
		ans.clear();
	}
	return 0;
}
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
	int i,j;
	string str;
	vector<char> ans,strA,strB;
	while(getline(cin,str)){
		for(i=0;i<str.size();i++)
			strA.push_back(str[i]);
		getline(cin,str);
		for(i=0;i<str.size();i++)
			strB.push_back(str[i]);
		sort(strA.begin(),strA.end());
		sort(strB.begin(),strB.end());
		for(i=0;i<strA.size();i++){
			for(j=0;j<strB.size();j++){
				if(strA[i]==strB[j]&&strB[j]!='0'){
					ans.push_back(strA[i]);
					strA[i]=strB[j]='0';
				}
			}
		}
		for(i=0;i<ans.size();i++){
			printf("%c",ans[i]);
		}
		printf("\n");
		ans.clear();
		strA.clear();
		strB.clear();
	}
	return 0;
}
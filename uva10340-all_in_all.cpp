//ncku9 uva10340 ALL IN ALL
#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

int main()
{
	string str1,str2;
	int i,j,find,code;
	while(cin >> str1 >> str2){
		i=-1;
		j=-1;
		find=0;
		code=1;
		while(++i<str1.size()){
			find=0;
			while(++j<str2.size()){
				if(str1[i]==str2[j]){
					find=1;
					break;
				}
			}
			if(!find){
				code=0;
				break;
			}
			if(!code)
				break;
		}
		if(code)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
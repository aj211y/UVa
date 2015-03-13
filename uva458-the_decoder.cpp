#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
	string str;
	int i;
	while(getline(cin,str)){
		for(i=0;i<str.size();i++)
			printf("%c",str[i]-7);
		printf("\n");
	}
	return 0;
}
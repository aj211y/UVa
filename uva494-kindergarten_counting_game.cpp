#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
	int count,i;
	string str="",line;
	while(getline(cin,line)){
		count=0;
		for(i=0;i<line.size();i++){
			if(line[i]>=65&&line[i]<=90 || line[i]>=97 && line[i] <=122 || line[i]=='\'')
				str=str+line[i];
			else{
				if(str!=""){
					count++;
					str="";
				}
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
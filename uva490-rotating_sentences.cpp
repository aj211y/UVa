//WA
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{	
	int i=-1,j=0,k,max=0;
	char map[110][110]={'\0'};
	string str;
	while(getline(cin,str)){
		i++;
		if(max<str.size())
			max=str.size();
		for(j=0;j<str.size();j++){
			map[i][j]=str[j];
		}
	}
	for(j=0;j<max;j++){
		for(k=i;k>=0;k--){
			if(map[k][j]=='\0')
				printf(" ");
			else
				printf("%c",map[k][j]);
		}
		printf("\n");
	}
	return 0;
}
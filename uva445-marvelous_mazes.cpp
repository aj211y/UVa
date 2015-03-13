#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int i,num=0,flag=0;
	char cha;
	while(scanf("%c",&cha)!=EOF){
		if(cha>=65 && cha <= 90 || cha=='b' || cha=='*'){
			for(i=0;i<num;i++){
				if(cha=='b')
					printf(" ");
				else if(cha=='*')
					printf("*");
				else
					printf("%c",cha);
			}
			num=0;
		}
		else{
			switch(cha){
				case '!':
				case '\n':
					printf("\n"); 
					if(num) num=0; break;
				default : num=num+cha-48; break;
			}
		}
	}
	return 0;
}
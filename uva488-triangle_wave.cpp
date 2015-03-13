#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int cases,A,F,i,j;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d %d",&A,&F);
		while(F--){
			for(i=1;i<A;i++){
				for(j=0;j<i;j++)
					printf("%d",i);
				printf("\n");
			}
			for(i=A;i>0;i--){
				for(j=0;j<i;j++)
					printf("%d",i);
				printf("\n");
			}
			if(F)
				printf("\n");
		}
		if(cases)
			printf("\n");
	}
	return 0;
}
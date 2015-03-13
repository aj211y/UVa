#include<iostream>
#include<cstdio>
#define MAX 13
using namespace std;
int solution[MAX],num[MAX];
bool used[MAX]={false};
void func(int k,int n)
{
	if(k==6){
		for(int i=0;i<6;i++){
			if(i)
				printf(" ");
			printf("%d",solution[i]);
		}
		printf("\n");
	}
	else{
		for(int i=0;i<n;i++){
			if(!used[i] && solution[k-1]<=num[i]){
				used[i]=true;
				solution[k]=num[i];
				func(k+1,n);
				used[i]=false;
			}
		}
	}
}
int main()
{
	int n,tmp,flag=0;
	while(scanf("%d",&n)!=EOF){
		if(!n)
			break;
		if(flag)
			printf("\n");
		flag=1;
		tmp=n;
		while(tmp){
			scanf("%d",&num[n-tmp--]);
		}
		func(0,n);
	}
	return 0;
}
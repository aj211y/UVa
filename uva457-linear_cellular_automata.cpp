#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

void print(int a)
{
	switch(a){
		case 0:printf(" "); break;
		case 1:printf("."); break;
		case 2:printf("x"); break;
		case 3:printf("W"); break;
		default: break;
	}
}
int main()
{
	bool flag=0;
	int cases,i,ans[40],tmp[40],j,program[10],value;
	scanf("%d",&cases);
	while(cases--){
		if(flag)
			printf("\n");
		flag=1;
		for(i=0;i<10;i++)
			scanf("%d",&program[i]);
		memset(ans,0,sizeof(ans));//這到底怎麼用?
		ans[19]=1;
		j=-1;
		while(++j<40)
			print(ans[j]);
		printf("\n");
		for(i=1;i<50;i++){
			j=0;
			while(j<40){
				if(j==0)
					value=ans[0]+ans[1];
				else if(j==39)
					value=ans[38]+ans[39];
				else
					value=ans[j-1]+ans[j]+ans[j+1];
				tmp[j]=program[value];
				print(tmp[j]);
				j++;
			}
			printf("\n");
			for(j=0;j<40;j++)
				ans[j]=tmp[j];
		}
		//printf("\n");
	}
	return 0;
}
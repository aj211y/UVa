#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int list[12000];
int main()
{
	bool flag=true;
	int L,H,R,i,first_L,max_R=0,preH=0;
	memset(list,0,sizeof(list));
	while(scanf("%d%d%d",&L,&H,&R)!=EOF)
	{
		if(flag)
			first_L=L;
		flag=false;
		for(i=L;i<R;i++)
		{
			if(H>list[i])
				list[i]=H;
		}
		if(R>max_R)
			max_R=R;
	}
	//printf("%d\n",first_L);
	flag=false;
	for(i=first_L;i<=max_R;i++)
	{
		if(list[i]!=preH)
		{
			if(flag)
				printf(" ");
			flag=true;
			printf("%d %d",i,list[i]);
			preH=list[i];
		}
	}
	printf("\n");
	return 0;
}
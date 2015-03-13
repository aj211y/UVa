#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int A ,L ,count=1,cases=1;
	long long int tmp;
	while(scanf("%d %d",&A,&L)!=EOF){
		if(A<0 && L<0)
			break;
		tmp=A;
		count = 1;
		while(tmp!=1){
			//printf("count=%d\n",count);
			if(tmp%2)//©_¼Æ
				tmp=3*tmp+1;
			else
				tmp=tmp/2;
			if(tmp>L)
				break;
			else
				count++;
		}
		printf("Case %d: A = %d, limit = %d, number of terms = %d\n",cases++,A,L,count);
	}
	return 0;
}
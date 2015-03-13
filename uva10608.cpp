#include<iostream>
#include<cstdio>
#define MAX 30001
int set[MAX],count[MAX]={0};
using namespace std;

long long int find(long long int x)
{
    if(x!=set[x])//當前位置不等於其所代表的值，表示他與其他人是朋友
        set[x]=find(set[x]);//找朋友
    return set[x];
}
void merge(long long int a,long long int b)
{
    set[find(a)]=find(b);
}

int main()
{
	long long int n,m,a,b,i,test,max,tmp;
	scanf("%lld",&test);
    while(test--)
    {
		max=0;
		tmp=0;
		scanf("%lld %lld",&n,&m);
		for(i=0;i<n;i++)//每一個人都是自己一個
			set[i]=i;
        for(i=0;i<m;i++)
        {
            scanf("%lld %lld",&a,&b);
            if(find(a)!=find(b)){
				//n--;
                merge(a,b);
			}
        }
		for(i=0;i<n;i++){
			tmp=find(i);
			count[tmp]++;
		}
		for(i=0;i<n;i++){
			if(count[i]>max)
				max=count[i];
		}
        printf("%d\n",max);
		for(i=0;i<MAX;i++)
			count[i]=0;
    }
	return 0;
}
#include<iostream>
#include<cstdio>
#define MAX 30001
int set[MAX],count[MAX]={0};
using namespace std;

long long int find(long long int x)
{
    if(x!=set[x])//��e��m�������ҥN���ȡA��ܥL�P��L�H�O�B��
        set[x]=find(set[x]);//��B��
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
		for(i=0;i<n;i++)//�C�@�ӤH���O�ۤv�@��
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
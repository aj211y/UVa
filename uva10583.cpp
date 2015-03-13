#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int line[50005];

int find(int num)
{
	if(num!=line[num])//表示他跟別人連起來了
		line[num]=find(line[num]);
	return line[num];
}
void merge(int a,int b)
{
	if(a!=find(a))
		line[line[a]]=find(b);
	line[a]=find(b);
}
int main()
{	
	int n,m,i,a,b,t=1;
	while(scanf("%d%d",&n,&m)&&(n|m)){
		for(i=0;i<n;i++)//個人自成一家
			line[i]=i;
		for(i=0;i<m;i++){
			scanf("%d%d",&a,&b);
			if(find(a)!=find(b)){//不在同一set但是現在要連起來
				//printf("f%d %d\n",find(a),find(b));
				n--;
				merge(a,b);
				//printf("m%d %d\n",find(a),find(b));
			}
		}
		printf("Case %d: %d\n",t++,n);
		memset(line,0,sizeof(line));
	}
	return 0;
}
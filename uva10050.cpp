#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int t,n,p,h,i,ans,tmp;
	bool day[4000];
	scanf("%d",&t);
	while(t--)
	{
		memset(day,false,sizeof(day));
		scanf("%d",&n);//n days
		scanf("%d",&p);//�X�ӬF��
		for(i=1;i<=p;i++)
		{
			scanf("%d",&h);
			tmp=h;
			while(tmp<=n)
			{
				day[tmp]=true;
				tmp+=h;
			}
		}
		ans=0;
		for(i=1;i<=n;i++)
		{
			if(i%7==0 || (i+1)%7==0)//§������§����
				continue;
			if(day[i])
				ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
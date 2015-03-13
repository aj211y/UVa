#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;

int line[11000];
int main()
{
	memset(line,0,sizeof(line));
	int mid=0,data,i,n=0,ans;
	while(scanf("%d",&data)!=EOF)
	{
		n++;
		if(mid==0)
		{
			line[1]=data;
			mid=1;
		}
		else
		{
			if(data <= line[mid])
			{
				for(i=n;i>=mid;i--)//©¹«á²¾
					line[i+1]=line[i];
				while(i>0)
				{
					if(data>=line[i])
					{
						line[i+1]=data;
						break;
					}
					line[i+1]=line[i];
					i--;
				}
				if(i==0)
					line[i+1]=data;
			}
			else //data > line[mid]
			{
				i=n-1;
				while(i>mid)
				{
					if(data>=line[i])
					{
						line[i+1]=data;
						break;
					}
					line[i+1]=line[i];
					i--;
				}
				if(i==mid)
					line[i+1]=data;
			}
		}
		mid=(n%2)?(n+1)/2:n/2;
		//printf("mid%d ",mid);
		ans=(n%2)?line[mid]:((line[mid]+line[mid+1])/2);
		/*if(n%2==1)
			printf("ans%d\n",line[mid]);
		else
			printf("ans%d\n",line[mid]);*/
		printf("%d\n",ans);
	}
	return 0;
}
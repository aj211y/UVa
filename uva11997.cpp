#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int k,i,j,data,m;
	vector<int> data1,data2,dataQ;
	while(scanf("%d",&k)!=EOF)
	{
		for(i=0;i<k;i++)
		{
			scanf("%d",&data);
			data1.push_back(data);
		}
		for(i=1;i<k;i++)
		{
			sort(data1.begin(),data1.end());
			for(j=0;j<k;j++)
			{
				scanf("%d",&data);
				data2.push_back(data);
			}
			sort(data2.begin(),data2.end());
			for(j=0;j<k;j++)
				dataQ.push_back(data1[j]+data2[0]);
			make_heap(dataQ.begin(),dataQ.end());
			for(j=1;j<k;j++)
			{
				for(m=0;m<k;m++)
				{
					data=data1[m]+data2[j];
					if(data<dataQ.front())
					{
						pop_heap(dataQ.begin(),dataQ.end());
						dataQ.pop_back();
						dataQ.push_back(data);
						push_heap(dataQ.begin(),dataQ.end());
					}
				}
			}
			copy(dataQ.begin(),dataQ.end(),data1.begin());
			data2.clear();
			dataQ.clear();
		}
		sort(data1.begin(),data1.end());
		printf("%d",data1[0]);
		for(i=1;i<k;i++)
			printf(" %d",data1[i]);
		printf("\n");
		data1.clear();
	}
	return 0;
}
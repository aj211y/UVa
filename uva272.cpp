#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

char str[1000100];
int main()
{
	int i;
	bool isFirst=true;
	
	while(fgets(str,1000100,stdin)!=NULL)
	{
		for(i=0;i<strlen(str);i++)
		{
			if(str[i]=='"')
			{
				if(isFirst)
				{
					printf("``");
					isFirst=false;
				}
				else
				{
					printf("''");
					isFirst=true;
				}
			}
			else
				printf("%c",str[i]);
		}
	}
	return 0;
}
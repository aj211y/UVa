#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>
using namespace std;

int main()
{
	bool dou,flag=false;
	int n,num,i;
	string str,tmp;
	set<string> tele;
	set<string>::iterator it;
	map<string,int> dic;
	scanf("%d",&n);
	while(n--)
	{
		if(flag)
			printf("\n");
		scanf("%d",&num);
		getchar();
		dou=false;
		tele.clear();
		dic.clear();
		while(num--)
		{
			tmp="";
			getline(cin,str);
			for(i=0;i<str.size();i++)
			{
				if(str[i]>='0' && str[i] <='9')
					tmp+=str[i];
				else if(str[i]>='A' && str[i] <='Z')
				{
					switch(str[i])
					{
						case 'A':
						case 'B':
						case 'C':
							tmp+='2';
							break;
						case 'D':
						case 'E':
						case 'F':
							tmp+='3';
							break;
						case 'G':
						case 'H':
						case 'I':
							tmp+='4';
							break;
						case 'J':
						case 'K':
						case 'L':
							tmp+='5';
							break;
						case 'M':
						case 'N':
						case 'O':
							tmp+='6';
							break;
						case 'P':
						case 'R':
						case 'S':
							tmp+='7';
							break;
						case 'T':
						case 'U':
						case 'V':
							tmp+='8';
							break;
						case 'W':
						case 'X':
						case 'Y':
							tmp+='9';
							break;
						default:break;
					}	
				}	
			}
			//cout << tmp << endl;
			if(tele.find(tmp)==tele.end())//new number
			{
				tele.insert(tmp);
				dic[tmp]=1;
			}
			else
			{
				dic[tmp]++;
				dou=true;
			}
		}
		if(dou)
		{
			for(it=tele.begin();it!=tele.end();it++)
			{
				tmp=*it;
				if(dic[tmp]!=1)
				{
					for(i=0;i<7;i++)
					{
						printf("%c",tmp[i]);
						if(i==2)
							printf("-");
					}
					printf(" %d\n",dic[tmp]);
				}
			}
		}
		else
			printf("No duplicates.\n");
		flag=true;
	}
	return 0;
}
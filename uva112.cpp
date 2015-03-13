#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;

int main()
{
	int ans,sum=0,num=0,l=0,r=0,i;
	char mem[4]={'\0'};
	stack<int> list;
	char cha;
	bool flag,neg=false;
	while(scanf("%d",&ans)!=EOF){
		getchar();
		flag=false;
		do{
			scanf("%c",&cha);
			switch(cha){
				case '(':
					l++;
					if(mem[2]!=')'){
						if(neg)
							num*=(-1);
						sum+=num;
						list.push(num);
						num=0;
						neg=false;
					}
					mem[0]=mem[1];
					mem[1]=mem[2];
					mem[2]=cha;
					break;
				case ')':
					r++;
					//printf("l%d r%d ",l,r);
					//for(i=0;i<3;i++)
					//	printf("%c ",mem[i]);
					//printf("sum%d ans%d" ,sum,ans);
					//printf("\n");
					if(!list.empty()&&mem[2]!='('){
						sum-=list.top();
						list.pop();
					}
					else if(mem[0]=='(' && mem[1]==')' && mem[2]=='(' && sum==ans)
						flag=true;
					mem[0]=mem[1];
					mem[1]=mem[2];
					mem[2]=cha;
					break;
				case '-':
					neg=true;
					break;
				case ' ':
				case '\n':
					break;
				default:
					num=num*10+(cha-48);
					break;
			}
		}while(l!=r);
		if(flag)
			printf("yes\n");
		else
			printf("no\n");
		while(!list.empty())
			list.pop();
		l=0;
		r=0;
		mem[0]=mem[1]=mem[2]='\0';
	}
	return 0;
}
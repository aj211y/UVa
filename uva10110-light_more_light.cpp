//ncku15  開關燈 有n顆燈泡就走n趟
//i                 f
//o o o o o o o o o o
//1 2 3 4 5 6 7 8 9 10
//(第k趟的時候)每次從i->f時，燈泡序列可被k整除者便按一下開關(亮燈或按燈)
//燈泡會亮的情況為總共按了奇數下，且只與k<=本身的趟數有關(比自己大以後就不再變動)
//因此只有完全平方數才會有奇數個因數
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	unsigned int input,tmp;
	while(scanf("%d",&input)!=EOF){
		if(!input)
			break;
		tmp=sqrt(input);
		if(tmp*tmp==input)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
//�p��B�ơA�C���u��W�[�δ��1�B�ΨB�Ƥ��� �A�D���I���̤p�B��
#include<iostream>
#include<cstdio>
using namespace std;
void count(int n);
int main()
{
	int test,start,end;
	scanf("%d",&test);
	while(test--){
		scanf("%d %d",&start,&end);
		count(end-start);
	}
	return 0;
}
void count(int n)
{
	int a=0,step=0,cal=0;
	while(n>1)
		n=n-2*(++a);
	if(n<0){
		n=n+2*a;
		step=2*(a-1);//����٪��B��
		while(n>1){
			n=n-a;
			cal++;
			if(n<0){
				n=n+a--;
				cal--;
			}
		}
		step=step+cal+n;
	}
	else
		step=2*a+n;
	printf("%d\n",step);
}
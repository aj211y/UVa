//10573 ncku11 input���@�Ӽ�(�����u����t) �� ��Ӽ�(������p�ꪺ�b�|r1 r2)
//�ҨD���n��PI*(R*R - r1*r1 - r2*r2)   R=r1+r2  �ѹϥi�D�o4*r1*r2=t*t/16
//          =PI*2*r1*r2  = PI*t*t/8
#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#define PI 2*acos(0)
using namespace std;

int main()
{
	int test,t1,t2,i,num=0;
	string str;
	scanf("%d",&test);
	scanf("\n");
	while(test--){
		getline(cin,str);
		i=-1;
		t1=0;
		t2=0;
		num=0;//�����@�ӼƩΨ�Ӽ�
		while(++i<str.size()){
			if(str[i]!= ' ')
				t1=t1*10+(str[i]-48);
			else{
				num=1;
				t2=t1;
				t1=0;
			}
		}
		if(t1<0||t2<0)
			printf("Impossible.\n");
		else if(num)
			printf("%.4lf\n",PI*2*t1*t2);
		else 
			printf("%.4lf\n",PI*t1*t1/8);
	}
	return 0;
}
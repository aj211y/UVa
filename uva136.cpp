/*
�ت��G�M��u��2 3 5�o�T�ӽ�]�Ʋզ����ƦC
���N���ɡA�N�h���
	"��N-1�� *2 �|�j���N��������"
	"��N-1�� *3 �|�j���N��������"
	"��N-1�� *5 �|�j���N��������"
�̤p�������N�O��N��

��N+1����
�i�H�q "��2�|�j���N-1��������" �~�򩹫��
�o�]�N�O�����򩳤U�n�Hm2 m3 m5�ӰO���O���@��
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

int main()
{
	int m2=0,m3=0,m5=0,i;
	int ugly[1510]={1};
	int pre_n=1;
	
	for(i=1;i<1500;i++)
	{
		for(;m2<i;m2++)
			if(ugly[m2]*2 > pre_n) 
				break;
		for(;m3<i;m3++)
			if(ugly[m3]*3 > pre_n)
				break;
		for(;m5<i;m5++)
			if(ugly[m5]*5 > pre_n)
				break;
		pre_n=min(ugly[m5]*5,min(ugly[m2]*2,ugly[m3]*3));
		ugly[i]=pre_n;
	}
	printf("The 1500'th ugly number is %d.\n",ugly[1499]);
	return 0;
}
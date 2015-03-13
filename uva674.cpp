/*
	coin change
	�� 1 5 10 25 50 �o���صw�� 
	���A�@�ӿ����ƥءA�ݥi���X�صw���զX
	dp~~~~~~~�����I�]���D
	
	�q�`�I�]���D�|�Q��n��h�֭ȶi�h
	�o�D�n�񪺬O " ��k�� "
	
 $$  0 1 2 3 4 5 6 7 8 9 10...
    ------------------------
	 1 1 1 1 1 1 1 1 1 1  1...��1���w���զ�����k��
	 . . . . . 2 2 2 2 2  3...��5���w���զ�����k��
	 
	 ���A�ಾ��{�Gf[n]=f[n-coin[i]];//coin[i]�N��{�b�O�έ��@�صw���A����
									 //n-coin[i]�N��ثe��n�����H�@��coin[i]������
									 //�ҥH�n���ۤv���զX�ƥ[�W(n-coin[i])���Ҧ����զX��
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define Max 8000 //���D�n�D�̦h�n�Ѫ��X7489
using namespace std;

int way[Max];
int coin[5]={1,5,10,25,50};
int main()
{
	int i,j,n;
	memset(way,0,sizeof(way));
	way[0]=1;
	for(i=0;i<5;i++)//���@�ӵw��
	{
		for(j=coin[i];j<8000;j++)  //�����O�n�� "�@��" �w��i �Ӵ���j�� �]�N�O��j��=coin[i]+�ѤU��$
		{						   //�ѤU��$�S���ܦh�զX���i��A�o�ɤ��n���ƭp��A���e��L��dp�ȴN�n
			way[j]+=way[j-coin[i]];//�ҥHj��=coin[i]+�ѤU��$ �o�˪��զX�ƴN�O�ѤU��$���Ҧ��զX��
		}						   //��j�����զX�ƧY���쥻���զX�Ƹ�j��=coin[i]+�ѤU��$�o�˪��զX�ƥ[�`
	}
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d\n",way[n]);
	}
	return 0;
}
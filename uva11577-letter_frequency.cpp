//ncku13 �r���X�{�W�v
#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

int main()
{
	int test,num,a=-1,count[26]={0},c,result;
	string str,tmp;
	scanf("%d",&test);
	scanf("\n");
	while(test--){
		getline(cin,str);
		a=-1;//��l��
		for(c=0;c<26;c++){//count��l��
			count[c]=0;
		}
		while(++a<str.size()){
			if((str[a]-'\0')>=65 && (str[a]-'\0') <=90 || (str[a]-'\0')>=97 && (str[a]-'\0') <=122){//�j�g���^��r���Τp�g��
				if((str[a]-'\0')>=65 && (str[a]-'\0') <=90){//�j�g���ন�Ʀr
					num=str[a]-65;
				}
				else{
					num=str[a]-97;//�p�g���ন�Ʀr
				}
				count[num]++;//�p����
			}
		}
		result=count[0];//����Ĥ@�ӷ�����
		for(c=0;c<26;c++){
			if(count[c]> result)//����X�̤j�ƭ�
				result=count[c];
		}
		for(c=0;c<26;c++){
			if(count[c]== result){//�C�L�̤j�ƭȪ��r��
				tmp=c+97+'\0';//�ഫ���p�g�r��
				cout << tmp;
			}
		}
		cout << endl;
	}
	return 0;
}
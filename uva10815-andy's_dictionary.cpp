//set �P�ˤ������|���Ƨl��  �۰ʱƧ�
#include<iostream>
#include<set>
#include<string>
#include<cstdlib>
#include<cctype>
using namespace std;
typedef set<string> set_str;

int main()
{
	int i;
	string str,word;
	set_str s;
	while(getline(cin,str)){
		word="";//�M�Ŧr��
		for(i=0;i<str.size();i++){
			if(str[i]>=65&&str[i]<=90){//�j�g�r��
				str[i]=tolower(str[i]);
				word=word+str[i];
			}
			else if(str[i]>=97&&str[i]<=122)//�p�g�r��
				word=word+str[i];
			else{
				if(word!="")//�s���Ӽ��I�Ÿ��|�N�Ŧr���J
					s.insert(word);//�N���r��J�r���
				word="";//�M�Ŧr��
			}
		}
		if(word!=""){//���檺�ɭ�
			s.insert(word);//�N���r��J�r���
			word="";//�M�Ŧr��
		}
	}
	set_str::iterator it;
	for(it=s.begin();it!=s.end();it++)
		cout << *it<<endl;
	return 0;
}
//ncku14  �P�_�O�_��11������  �̦h��1000��ơA�ҥH���ӭn��string�s�_�ӫᰵ�p��
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string n;
	int sum1=0,sum2=0,a=-1;
	while(getline(cin,n)){
		sum1=0;
		sum2=0;
		a=-1;
		if(n=="0")
			break;
		while(++a<n.size()){
			if(a%2)
				sum2=sum2+(n[a]-48);
			else
				sum1=sum1+(n[a]-48);
		}
		if((sum1-sum2)%11)
			cout << n << " is not a multiple of 11.\n";
		else
			cout << n << " is a multiple of 11.\n";
	}
	return 0;
}
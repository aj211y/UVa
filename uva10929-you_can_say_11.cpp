//ncku14  判斷是否為11的倍數  最多到1000位數，所以應該要用string存起來後做計算
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
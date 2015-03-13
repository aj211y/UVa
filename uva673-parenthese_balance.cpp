#include<iostream>
#include<cstdio>
#include<stack>
#include<string>
using namespace std;

int main()
{
	int x,a,bad=0;
	string key;
	stack<char> stk;
	cin >> x;
	getchar();//把換行符號拿掉
	while(x){
		bad=0;
		a=0;
		getline(cin,key);//讀到換行符號就會停止
		if(key=="\0")
			cout << "Yes" << endl;
		else{
			//bad=0;
			while(key[a]!='\0'){
				if(key[a]=='(' || key[a]=='[')
					stk.push(key[a]);
				else{
					if(stk.empty()){
						bad=1;
						break;
					}
					switch(key[a]){
						case ')':
							if(stk.top()!='('){
								bad=1;
								break;
							}
							break;
						case ']':
							if(stk.top()!='['){
								bad=1;
								break;
							}
							break;
					}
					stk.pop();
				}
				a++;
			}
			if(!stk.empty()){
				bad=1;
			}
			if(!bad)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		while(!stk.empty())
			stk.pop();
		x--;
	}
	return 0;
}

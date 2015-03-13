//set 同樣元素不會重複吸收  自動排序
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
		word="";//清空字串
		for(i=0;i<str.size();i++){
			if(str[i]>=65&&str[i]<=90){//大寫字母
				str[i]=tolower(str[i]);
				word=word+str[i];
			}
			else if(str[i]>=97&&str[i]<=122)//小寫字母
				word=word+str[i];
			else{
				if(word!="")//連續兩個標點符號會將空字串輸入
					s.insert(word);//將此字放入字典裡
				word="";//清空字串
			}
		}
		if(word!=""){//換行的時候
			s.insert(word);//將此字放入字典裡
			word="";//清空字串
		}
	}
	set_str::iterator it;
	for(it=s.begin();it!=s.end();it++)
		cout << *it<<endl;
	return 0;
}
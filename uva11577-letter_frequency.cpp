//ncku13 ダ瞷繵瞯
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
		a=-1;//﹍て
		for(c=0;c<26;c++){//count﹍て
			count[c]=0;
		}
		while(++a<str.size()){
			if((str[a]-'\0')>=65 && (str[a]-'\0') <=90 || (str[a]-'\0')>=97 && (str[a]-'\0') <=122){//糶璣ゅダ┪糶
				if((str[a]-'\0')>=65 && (str[a]-'\0') <=90){//糶锣Θ计
					num=str[a]-65;
				}
				else{
					num=str[a]-97;//糶锣Θ计
				}
				count[num]++;//璸Ω计
			}
		}
		result=count[0];//р材讽ゑ耕
		for(c=0;c<26;c++){
			if(count[c]> result)//т程计
				result=count[c];
		}
		for(c=0;c<26;c++){
			if(count[c]== result){//程计ダ
				tmp=c+97+'\0';//锣传Θ糶ダ
				cout << tmp;
			}
		}
		cout << endl;
	}
	return 0;
}
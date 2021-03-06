//10573 ncku11 input為一個數(公切線長度t) 或 兩個數(內切兩小圓的半徑r1 r2)
//所求面積為PI*(R*R - r1*r1 - r2*r2)   R=r1+r2  由圖可求得4*r1*r2=t*t/16
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
		num=0;//紀錄一個數或兩個數
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
//ncku8  一堆數字 找出由任何一點到所有點的距離最小和
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int kk(vector<int> vito,int sum);
int main()
{
	int test,rela,street,sum=0,tmp;
	vector<int> vito;
	scanf("%d",&test);
	while(test--){
		sum=0;//初始化
		scanf("%d",&rela);//有幾位親戚
		tmp=rela;
		while(tmp--){
			scanf("%d",&street);//住哪
			vito.push_back(street);
			sum=sum+street;
		}
		sum=sum/rela;//中間值
		tmp=kk(vito,sum);//tmp暫存 之後做比較
		if(tmp < kk(vito,sum+1)){ //往前找
			while(tmp > kk(vito,sum-1))
				tmp=kk(vito,--sum);
		}
		else{
			while(tmp > kk(vito,sum+1))//往後找
				tmp=kk(vito,++sum);
		}
		printf("%d\n",tmp);
		vito.clear();//清空
	}
	return 0;
}
int kk(vector<int> vito,int sum)
{
	int c=-1,result=0;
	while(++c<vito.size()){
		if(vito[c]<sum)//距離是絕對值，所以要比較誰大誰小，看誰減誰
			result=result+sum-vito[c];
		else
			result=result+vito[c]-sum;
	}
	return result;
}
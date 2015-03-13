//橢圓面積 拍ab
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

double pi=acos(-1.0);
//double pi=3.1415928; <-- 用這個會錯
int main()
{
	int n;
	double D,L,a,b;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%lf %lf",&D,&L);
		a=sqrt(pow(L/2,2)-pow(D/2,2));
		b=L/2;
		printf("%.3lf\n",pi*a*b);
	}
	return 0;
}
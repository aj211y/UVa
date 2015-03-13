#include <iostream>
#include <algorithm>
using namespace std;

int str[1000];
int i=0,result=0;
void store(int num);
void bubble(int in[], int n);
int main()
{
	int x,num,tmp;
	while(cin >> x){
		result=0;
		i=0;
		tmp=x;
		while(tmp){
			cin >> num;
			store(num);
			tmp--;
		}
		bubble(str,x);
		cout << "Minimum exchange operations : " << result << endl;
	}
	return 0;
}
void store(int num)
{
	str[i++]=num;
}
void bubble(int in[], int n)
{
	int k, j;
	for(k=n-1; k>=1;k--)
	    for(j=0; j<k; j++)
            if(in[j]>in[j+1]){ 
				swap(in[j], in[j+1]);
				result++;
		    }
}

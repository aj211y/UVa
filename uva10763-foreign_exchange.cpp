#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 500000


int p1[MAXN],p2[MAXN];
int main()
{
	int n,tmp;
	while(cin >> n){
		if(!n)
			break;
		tmp=0;
		while(tmp<n){
			cin >> p1[tmp] >> p2[tmp];
			tmp++;
		}
		sort(p1,p1+n);//sort(°}¦CÀY,°}¦C§À)
		sort(p2,p2+n);
		for(int a=0;a<n;a++){
			if(p1[a]!=p2[a]){
				cout << "NO" << endl;
				break;
			}
			else if(a==n-1)
				cout << "YES" << endl;
		}
	}
	return 0;
}
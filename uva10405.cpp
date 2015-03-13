#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
using namespace std;

int LCS[1100][1100];
int main()
{
	string strA,strB;
	int i,j;
	while(getline(cin,strA)){
		getline(cin,strB);
		memset(LCS,0,sizeof(LCS));
		for(i=0;i<strA.size();i++){
			for(j=0;j<strB.size();j++){
				if(strA[i]==strB[j])
					LCS[i+1][j+1]=LCS[i][j]+1;
				else
					LCS[i+1][j+1]=max(LCS[i+1][j],LCS[i][j+1]);
			}
		}
		printf("%d\n",LCS[strA.size()][strB.size()]);
	}
	return 0;
}
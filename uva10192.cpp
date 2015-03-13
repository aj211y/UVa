#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;

int LCS[110][110];
int main()
{
	int i,j,number=1;
	string lineA,lineB;
	while(getline(cin,lineA)){
		if(lineA=="#")
			break;
		getline(cin,lineB);
		memset(LCS,0,sizeof(LCS));
		for(i=0;i<lineA.size();i++){
			for(j=0;j<lineB.size();j++){
				if(lineA[i]==lineB[j])
					LCS[i+1][j+1]=LCS[i][j]+1;
				else
					LCS[i+1][j+1]=max(LCS[i][j+1],LCS[i+1][j]);
			}
		}
		printf("Case #%d: you can visit at most %d cities.\n",number++,LCS[lineA.size()][lineB.size()]);
	}
	return 0;
}
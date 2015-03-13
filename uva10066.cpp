#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

int LCS[110][110];
int main()
{
	vector<int> towerA,towerB;
	int i,j,data,a,b,number=1;
	while(scanf("%d%d",&a,&b)&&(a|b)){
		memset(LCS,0,sizeof(LCS));
		for(i=0;i<a;i++){
			scanf("%d",&data);
			towerA.push_back(data);
		}
		for(i=0;i<b;i++){
			scanf("%d",&data);
			towerB.push_back(data);
		}
		for(i=0;i<towerA.size();i++){
			for(j=0;j<towerB.size();j++){
				if(towerA[i]==towerB[j])
					LCS[i+1][j+1]=LCS[i][j]+1;
				else
					LCS[i+1][j+1]=max(LCS[i+1][j],LCS[i][j+1]);
			}
		}
		printf("Twin Towers #%d\n",number++);
		printf("Number of Tiles : %d\n\n",LCS[towerA.size()][towerB.size()]);
		towerA.clear();
		towerB.clear();
	}
	return 0;
}
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<stack>
using namespace std;

vector<string> lineA,lineB;
int LCS[110][110];
int loc[110][110];
void lcs()
{
	int i,j;
	stack<string> ans;
	memset(LCS,0,sizeof(LCS));
	memset(loc,0,sizeof(loc));
	for(i=0;i<lineA.size();i++){
		for(j=0;j<lineB.size();j++){
			if(lineA[i]==lineB[j]){
				LCS[i+1][j+1]=LCS[i][j]+1;
				loc[i+1][j+1]=1;
			}
			else{
				if(LCS[i][j+1]>LCS[i+1][j]){
					LCS[i+1][j+1]=LCS[i][j+1];
					loc[i+1][j+1]=2;
				}
				else{
					LCS[i+1][j+1]=LCS[i+1][j];
					loc[i+1][j+1]=3;
				}
			}
		}
	}
	for(i=lineA.size(),j=lineB.size();i>0,j>0;){
		if(loc[i][j]==1){
			ans.push(lineA[i-1]);
			i--;
			j--;
		}
		else if(loc[i][j]==2)
			i--;
		else
			j--;
	}
	while(!ans.empty()){
		printf("%s",ans.top().c_str());
		ans.pop();
		if(ans.empty())
			printf("\n");
		else
			printf(" ");
	}
	lineA.clear();
	lineB.clear();
}
int main()
{
	int number=0;
	string str;
	while(cin>>str){
		if(str=="#"){
			number++;
			if(number%2)
				continue;
			else
				lcs();
		}
		else{
			if(number%2)
				lineB.push_back(str);
			else
				lineA.push_back(str);
		}
	}
	return 0;
}
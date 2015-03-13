#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int f[10005],b[10005];
int main()
{
	int n,d,max,i,ans;
	vector<int> line,lisf,lisb;
	while(scanf("%d",&n)!=EOF){
		while(n--){
			scanf("%d",&d);
			line.push_back(d);
		}
		memset(f,0,sizeof(f));
		memset(b,0,sizeof(b));
		lisf.push_back(line[0]);
		f[0]=lisf.size();
		for(i=1;i<line.size();i++){
			if(lisf.back()<line[i]){
				lisf.push_back(line[i]);
				f[i]=lisf.size();
			}
			else{
				*lower_bound(lisf.begin(),lisf.end(),line[i])=line[i];
				f[i]=lower_bound(lisf.begin(),lisf.end(),line[i])-lisf.begin()+1;
			}
		}
		lisb.push_back(line.back());
		b[line.size()-1]=lisb.size();
		for(i=line.size()-2;i>=0;i--){
			if(lisb.back()<line[i]){
				lisb.push_back(line[i]);
				b[i]=lisb.size();
			}
			else{
				*lower_bound(lisb.begin(),lisb.end(),line[i])=line[i];
				b[i]=lower_bound(lisb.begin(),lisb.end(),line[i])-lisb.begin()+1;
			}
		}
		/*for(i=0;i<line.size();i++){
			printf("f%d b%d\n",f[i],b[i]);
		}
		printf("\n");*/
		ans=max=1;
		for(i=0;i<line.size();i++){
			ans=min(f[i],b[i])*2-1;//จาคl 2345343
			if(ans>max)
				max=ans;
		}
		printf("%d\n",max);
		line.clear();
		lisf.clear();
		lisb.clear();
	}
	return 0;
}
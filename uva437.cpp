#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

struct dimen
{
	int x,y,z;
};
vector<dimen> box;
void setbox(int x,int y,int z)
{
	dimen abox;
	abox.x=x;
	if(y>z){
		abox.y=y;
		abox.z=z;
	}
	else{
		abox.y=z;
		abox.z=y;
	}
	box.push_back(abox);
	
	abox.x=z;
	if(x>y){
		abox.y=x;
		abox.z=y;
	}
	else{
		abox.y=y;
		abox.z=x;
	}
	box.push_back(abox);
	abox.x=y;
	if(x>z){
		abox.y=x;
		abox.z=z;
	}
	else{
		abox.y=z;
		abox.z=x;
	}
	box.push_back(abox);
}
bool cmp(const dimen &a,const dimen &b)
{
	if(a.y<b.y)
		return true;
	else
		return false;
}
int bigger[100][100]={0};
int dp[100]={0};
int main()
{
	int n,number=1,i,j,ans=0,x,y,z;
	
	while(scanf("%d",&n)&&n){
		for(i=0;i<n;i++){
			scanf("%d%d%d",&x,&y,&z);
			setbox(x,y,z);
		}
		sort(box.begin(),box.end(),cmp);
		for(j=1;j<box.size();j++){
			for(i=0;i<j;i++){
				if(box[i].y<box[j].y && box[i].z<box[j].z)
					bigger[i][j]=1;
			}
		}
		ans=0;
		for(i=0;i<box.size();i++)
			dp[i]=box[i].x;
		for(j=1;j<box.size();j++){
			for(i=0;i<j;i++){
				if(bigger[i][j] && dp[j]<dp[i]+box[j].x)
					dp[j]=dp[i]+box[j].x;
			}
			if(ans<dp[j])
				ans=dp[j];
		}
		printf("Case %d: maximum height = %d\n",number++,ans);
		box.clear();
		memset(dp,0,sizeof(dp));
		memset(bigger,0,sizeof(bigger));
	}
	return 0;
}
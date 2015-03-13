#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int bigger[50][50]={0};//bigger[i][j] 存第j個box有沒有大於第i個box
struct line
{
	int id;
	vector<int>list;
};
bool cmp(const line &a,const line &b)
{
	//if(a.list[0]<b.list[0])
	return a.list[0]<b.list[0] ? true : false;
}
int main()
{
	int k,n,i,j,t,z;
	int ans,ansi;
	line data;
	int dp[50]={0},path[50];
	vector<line> box;
	while(scanf("%d%d",&k,&n)!=EOF){
		for(i=0;i<k;i++){
			data.id=i+1;
			for(j=0;j<n;j++){
				scanf("%d",&t);
				data.list.push_back(t);
			}
			sort(data.list.begin(),data.list.end());
			box.push_back(data);
			data.list.clear();
		}
		sort(box.begin(),box.end(),cmp);
		for(j=1;j<k;j++){//第j個box
			for(i=0;i<j;i++){//第i個box
				for(z=0;z<n;z++){//box裡的各維度數字
					if(box[i].list[z]>=box[j].list[z]) break;//表示第i個box有某一維度不能裝進第j個box
				}
				if(z==n) bigger[i][j]=1;//表是第i個box可以裝進第j個box
			}
		}
		for(i=0;i<50;i++){//初始化
			dp[i]=1;
			path[i]=i;
		}
		ans=ansi=1;
		for(j=1;j<k;j++){
			for(i=0;i<j;i++){
				if(bigger[i][j]&&dp[j]<dp[i]+1){//i-box可裝進j-box 且 j-box的dp 小於 i-box的dp+1
					dp[j]=dp[i]+1;
					path[j]=i;//路徑為上一個的位置i
				}
			}
			if(dp[j]>ans){//ans為最長的路徑
				ans=dp[j];
				ansi=i;//ansi為最長路徑的前一個位置i
			}
		}
		printf("%d\n",ans);//列印長度
		k=0;
		while(1)
		{
			dp[k++]=ansi;//從最後面找回來
			if(ansi == path[ansi]) break;//表示已找到開頭
			ansi = path[ansi];
		}
		for(i=k-1;i>=0;i--){
			printf(i==0? "%d\n" : "%d ",box[dp[i]].id);
		}
		box.clear();
		for(i=0;i<50;i++){
			for(j=0;j<50;j++){
				bigger[i][j]=0;
			}
		}
	}
	return 0;
}
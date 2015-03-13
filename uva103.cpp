#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int bigger[50][50]={0};//bigger[i][j] �s��j��box���S���j���i��box
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
		for(j=1;j<k;j++){//��j��box
			for(i=0;i<j;i++){//��i��box
				for(z=0;z<n;z++){//box�̪��U���׼Ʀr
					if(box[i].list[z]>=box[j].list[z]) break;//��ܲ�i��box���Y�@���פ���˶i��j��box
				}
				if(z==n) bigger[i][j]=1;//��O��i��box�i�H�˶i��j��box
			}
		}
		for(i=0;i<50;i++){//��l��
			dp[i]=1;
			path[i]=i;
		}
		ans=ansi=1;
		for(j=1;j<k;j++){
			for(i=0;i<j;i++){
				if(bigger[i][j]&&dp[j]<dp[i]+1){//i-box�i�˶ij-box �B j-box��dp �p�� i-box��dp+1
					dp[j]=dp[i]+1;
					path[j]=i;//���|���W�@�Ӫ���mi
				}
			}
			if(dp[j]>ans){//ans���̪������|
				ans=dp[j];
				ansi=i;//ansi���̪����|���e�@�Ӧ�mi
			}
		}
		printf("%d\n",ans);//�C�L����
		k=0;
		while(1)
		{
			dp[k++]=ansi;//�q�̫᭱��^��
			if(ansi == path[ansi]) break;//��ܤw���}�Y
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
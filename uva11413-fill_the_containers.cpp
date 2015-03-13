#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int canbe(int mid,vector<int> milk)
{
	int i=-1,group=0,div=0;
	while(++i<milk.size()){
		group=group+milk[i];
		if(group>mid){
			group=0;
			div++;
			i--;
		}
	}
	return div; //�����X��
}
int main()
{
	int n,m,i,bottle,beg,end,mid;
	vector<int> milk;
	while(scanf("%d %d",&m,&n)!=EOF){
		beg=end=0;
		for(i=0;i<m;i++){
			scanf("%d",&bottle);
			milk.push_back(bottle);
			if(bottle>beg)
				beg=bottle;
			end=end+bottle;
		}
		while(beg<end){
			mid=(beg+end)/2;
			if(canbe(mid,milk)<n)//�p�G��n�p��ܥi�H�A���U��
				end=mid;
			else
				beg=mid+1;//�n�Y�p�d��
		}
		printf("%d\n",beg);
		milk.clear();
	}
	return 0;
}
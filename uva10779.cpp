#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define Max 40
#define INF 1000000
using namespace std;

int cap[Max][Max],v[Max],flow[Max][Max],p[Max];
bool DFS(int cur,int t)
{
	int i,j,k;
	v[cur]=1;
	if(cur==t)
		return true;
	for(i=0;i<=t;i++)
	{
		if(v[i]) continue;
		if(cap[cur][i]-flow[cur][i]>0 || flow[i][cur]>0)
		{
			p[i]=cur;
			if(DFS(i,t))return true;
		}
	}
	return false;
}
int FindFlow(int s,int t)
{
	int i,j,k,pre;
	int f=INF;
	//��bottle neck
	for(i=t;i!=s;i=pre)
	{
		pre=p[i];
		if(cap[pre][i]-flow[pre][i]>0)
			f=min(f,cap[pre][i]-flow[pre][i]);
		else
			f=min(f,flow[i][pre]);
	}
	//��s��
	for(i=t;i!=s;i=pre)
	{
		pre=p[i];
		if(cap[pre][i]-flow[pre][i]>0)
			flow[pre][i]+=f;
		else
			flow[i][pre]-=f;
	}
	return f;
}
int FordFulkerson(int s,int t)
{
	int i,j,k;
	int ret=0;
	memset(flow,0,sizeof(flow));
	while(1)
	{
		memset(v,0,sizeof(v));//visited
		if(!DFS(s,t))
			break;
		ret+=FindFlow(s,t);
	}
	return ret;
}
int main()
{
	int T,i,n,m,j,num,k,item,ans;
	bool posess[30];//���S���֦��o�ت��~�F
	scanf("%d",&T);//�X��test cases
	for(i=1;i<=T;i++)
	{
		scanf("%d%d",&n,&m);//n�ӤHm�ت��~
		memset(cap,0,sizeof(cap));
		memset(posess,false,sizeof(posess));
		scanf("%d",&num);
		for(k=0;k<num;k++)
		{
			scanf("%d",&item);
			cap[0][item]++;
		}
		for(k=1;k<=m;k++)//T�I ��Bob�̫�֦��X�ت��~
			cap[k][n+m]=1;
		for(j=1;j<n;j++)//Bob�B�ͦ����F��--�ع�
		{
			memset(posess,false,sizeof(posess));
			scanf("%d",&num);
			for(k=0;k<num;k++)
			{
				scanf("%d",&item);
				if(!posess[item])
					posess[item]=true;
				else
					cap[m+j][item]++;//��j�ӪB�ͦ��h�l��item�i�H���X�ӥ洫
			}
			for(k=1;k<=m;k++)//1~m�O���~���I
			{
				if(!posess[k])//��j�ӪB�ͨS���o�ӪF��
					cap[k][m+j]=1;
			}
		}//�عϧ���
		ans=FordFulkerson(0,n+m);
		printf("Case #%d: %d\n",i,ans);
	}
	return 0;
}
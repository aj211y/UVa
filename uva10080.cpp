#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

struct node
{
	double x,y;
}gopher[120],hole[120];
vector <int> list[120];//�O�������I���s��k������I

bool used[120];//�k�䪺�I�ιL�F�S
int rlink[120],llink[120];
bool DFS(int now)
{
	int i,next;
	//���L�o�@�I�Ҧ��۳s����
	for(i=0;i<list[now].size();i++)
	{
		next=list[now][i];
		if(!used[next])
		{
			used[next]=true;
			//�k��o�I�S��match�L�A�Ϊ̥L�i�H��O�Hmatch�A��o�Ӧ�m���X��
			if(!rlink[next]||DFS(rlink[next]))
			{
				llink[now]=next;
				rlink[next]=now;
				return true;
			}
		}
	}
	//�䤣��i�Hmatch��
	return false;
}
int bipartite(int L,int R)
{
	int i,ans=0;
	//�����k�䳣�٨S��match����H
	memset(rlink,0,sizeof(rlink));
	memset(llink,0,sizeof(llink));
	for(i=1;i<=L;i++)
	{
		memset(used,false,sizeof(used));//�k�䪺�I���٨S�ιL
		if(DFS(i))
			ans++;
	}
	return ans;
}
int main()
{
	int n,m,s,v,i,j,num;
	double limit;
	while(scanf("%d%d%d%d",&n,&m,&s,&v)!=EOF)
	{
		memset(list,0,sizeof(list));
		limit=s*v;//�@���̦h�i�]���Z��
		//the position a gopher stands
		for(i=1;i<=n;i++)
			scanf("%lf%lf",&gopher[i].x,&gopher[i].y);
		for(i=1;i<=m;i++)
			scanf("%lf%lf",&hole[i].x,&hole[i].y);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(sqrt(pow(hole[j].x-gopher[i].x,2)+pow(hole[j].y-gopher[i].y,2))<=limit)
					list[i].push_back(j);
			}
		}
		num=bipartite(n,m);
		printf("%d\n",n-num);
	}
	return 0;
}
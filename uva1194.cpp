/*Bipartite matching
A ������0~n-1��mode
B ������0~m-1��mode

���D��bipartite graph

����A mode ��x�s, B mode ��y�s
�s�����䬰�U��job

�䦹�Ϫ�bipartite matching M
�]�����S�����@�I�A���M���ֻ̤ݭn��O���ಾ�ɶ��A��L��@�w�i�H�Q�л\

�Y��mode 0�i�H���檺�A�N���ݫ���F�A�]���@�}�l�N�bmode 0���U
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int llink[110],rlink[110];
bool used[110];
vector<int> list[110];
bool DFS(int now)
{
	int i,next;
	for(i=0;i<list[now].size();i++)//���Lnow�o�I���Ҧ��۳s��
	{
		next=list[now][i];
		if(!used[next])
		{
			used[next]=true;
			if(!rlink[next] || DFS(rlink[next]))
			{
				rlink[next]=now;
				llink[now]=next;
				return true;
			}
		}
	}
	return false;
}
int bipartite(int L)
{
	int i,ret=0;
	memset(llink,0,sizeof(llink));
	memset(rlink,0,sizeof(rlink));
	for(i=1;i<L;i++)//���䪺�C���I�����L�h	
	{
		memset(used,false,sizeof(used));
		if(DFS(i))
			ret++;
	}
	return ret;
}
int main()
{
	int n,m,k,i,id,a,b,ans;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		for(i=0;i<110;i++)
			list[i].clear();
		scanf("%d%d",&m,&k);
		for(i=0;i<k;i++)
		{
			scanf("%d%d%d",&id,&a,&b);
			if(a*b!=0)//�p�Ga��b��@��0�A�h���ݵe�J�Ϥ��A�]���@�}�l�N�Omode 0
				list[a].push_back(b);
		}
		ans=bipartite(n);
		printf("%d\n",ans);
	}
	return 0;
}
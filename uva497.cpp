//DP-LIS
//O(n^2)
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string> //atoi
#include <stack>
#define MAX 1000
using namespace std;

int list[MAX],p[MAX],dp[MAX];
//�o�̪�dp[i]�s���N�O�H��i�ӼƦr�������̪����W�l�ǦC
char buffer[MAX/10];
int main()
{
	int T,num,n,M,M_end,i;
	bool first=true;
	stack <int> ans;
	scanf("%d\n",&T);
	while(T--)
	{
		if(!first)
			printf("\n");
		first=false;
		n=0;
		while(fgets(buffer,sizeof(buffer),stdin))
		{
			//�p�GŪ���@�Ӵ���A��ܦ������굲��
			if(buffer[0]=='\n')
				break;
			num=atoi(buffer); //include <string>
			list[n++]=num;
		}
		for(i=0;i<n;i++)
		{
			//�C�ӤH�̪쪺LIS���׬�1
			dp[i]=1;
			//�C�ӤH�쥻��parent���ۤv
			p[i]=i;
		}
		//LIS
		//i=0��(�Ĥ@�ӼƦr)�A���� �Ĥ@�ӼƵ�����LIS
		M=1;
		M_end=0;
		for(i=1;i<n;i++)
		{
			for(int j=i-1;j>=0;j--)
			{
				//�p�G��i�ӼƤ��j�ӼƤj(��ܥi�H���b��j�Ӽƫ᭱)
				//�B �H��j�ӼƵ���������+1 �� �H��i�ӼƵ��������� ������
				//�h��s ����dp �Ӧۭ���(p)
				if(list[i]>list[j] && dp[j]+1>dp[i])
				{
					dp[i]=dp[j]+1;
					p[i]=j;
				}
			}
			if(M<dp[i])
			{
				M=dp[i];
				M_end=i;
			}
		}
		printf("Max hits: %d\n",M);
		
		for(i=M_end;i!=p[i];i=p[i])
			ans.push(list[i]);
		ans.push(list[i]);
		while(!ans.empty())
		{
			printf("%d\n",ans.top());
			ans.pop();
		}
	}
	return 0;
}
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;


//(B^P)%M = (B^(P/2)%M) * (B^(P/2)%M)
long long int modpow(long long int B,long long int P,long long int M)
{
	long long int result;
	if(P==0)
		return 1;
	else if(P==1)
		return B%M;
	else
	{
		result=modpow(B,P/2,M);
		if(P%2)
			return result*result*B%M;
		else
			return result*result%M;
	}
	
}
int main()
{
	long long int B,M,P,ans;
	while(cin >> B >> P >> M)
	{
		ans=modpow(B,P,M);
		cout << ans << endl;
	}
	return 0;
}

//·|TLE
/*int main()
{
	long long int B,P,M,i,tmp,num,ans;
	vector<long long int> list;
	set<long long int> record;
	while(cin>>B>>P>>M)
	{
		//memset(list,0,sizeof(list));
		tmp=1;
		for(i=0;i<P;i++)
		{
			tmp=(tmp*B)%M;
			if(record.find(tmp)==record.end())
			{
				list.push_back(tmp);
				record.insert(tmp);
			}
			else
				break;
		}
		num=list.size();
		ans=P%num;
		//cout << ans << endl;
		if(ans==0)
			ans=num-1;
		else
			ans=ans-1;
		cout << list[ans] << endl;
		list.clear();
		record.clear();
	}
	return 0;
}*/
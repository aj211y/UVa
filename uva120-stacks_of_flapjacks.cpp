//½��  �Ϥ��ƧǦn  
/*��X��  �n���L�ƧǦn�ݦb���Ǧ�m���J�٤M
4 3 2 1 5
  <----|   ��m 2
1 2 3 4 5

2 5 7 6 4 8
  <--|      ��m 4
7 5 2 6 4 8
    <----|  ��m 2
4 6 2 5 7 8
<--|        ��m 5
6 4 2 5 7 8
   <---|    ��m 3
5 2 4 6 7 8
  <--|      ��m 4
4 2 5 6 7 8
<--|        ��m 5
2 4 5 6 7 8

�ҥH�o�˪���X��
4 3 2 1 5(�o�̤��঳�Ů��)
2 4 2 5 3 4 5 0
*/
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int find(int value,vector<int> line)
{
	int i=-1;
	while(++i < line.size()){
		if(value==line[i])
			return i;
	}
}
void check(int value,vector<int> &line,queue<int> &count)
{
	int tmp,max,i;
	i=value-1;
	max=line[i];
	tmp=i;
	while(--i>=0){
		if(max<line[i]){ 
			max=line[i];
			tmp=i;//�����̤j�Ȫ���m
		}	
	}
	if(tmp!=value-1){
		if(!tmp){//�n½�઺�Ʀ��Ĥ@�Ӧ�m
			reverse(line.begin(),line.begin()+value);
			count.push((line.size()-value+1));
		}
		else{//½�઺�ƥd�b����
			reverse(line.begin(),line.begin()+tmp+1);//��½��Ĥ@��
			reverse(line.begin(),line.begin()+value);//�A½�쥿�T��m
			count.push((line.size()-tmp));
			count.push((line.size()-value+1));
		}
	}
	if(value-1)
		check(value-1,line,count);//�]���n��̤j�ƥH�e�������ƧǦn�A�o�ˤ~�O½�̤֦���
}
void flip(int value,vector<int> &line,int last,queue<int> &count)
{
	int tmp,i;
	if(value==0){//�n½�઺�Ʀ��Ĥ@�Ӧ�m
		reverse(line.begin(),line.begin()+last+1);
		count.push((line.size()-last));
	}
	else{//½�઺�ƥd�b����
		check(value,line,count);
		reverse(line.begin(),line.begin()+value+1);//���½��Ĥ@��
		reverse(line.begin(),line.begin()+last+1);//�A½�쥿�T��m
		count.push((line.size()-value));
		count.push((line.size()-last));
	}
}
int main()
{
	string str;
	int i,tmp,l;
	vector<int> cakes,tmpcake,final;
	queue<int> count;
	while(getline(cin,str)){
		i=-1;
		tmp=0;
		while(++i<str.size()){
			if(str[i] != ' ')
				tmp=tmp*10+(str[i]-48);
			else{
				cakes.push_back(tmp);
				tmpcake.push_back(tmp);
				final.push_back(tmp);
				tmp=0;
			}
		}
		cakes.push_back(tmp);
		tmpcake.push_back(tmp);
		final.push_back(tmp);
		sort(tmpcake.begin(),tmpcake.end());//tmpcake���w�g�ƧǦn��
		l=tmpcake.size();
		while(--l>=0){
			tmp=find(tmpcake[l],cakes);//�M��cakes���̤j�ƪ���m
			if(tmp!=l)//���b�L���Ӧb����m�W
				flip(tmp,cakes,l,count);//½��
		}
		count.push(0);
		i=-1;
		while(++i<final.size()){
			printf("%d",final[i]);
			if(i!=final.size()-1)
				printf(" ");
		}
		printf("\n");
		while(!count.empty()){
			cout << count.front();
			count.pop();
			if(!count.empty())
				printf(" ");
		}
		printf("\n");
		cakes.clear();
		tmpcake.clear();
		final.clear();
	}
	return 0;
}
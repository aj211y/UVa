//翻餅  使之排序好  
/*輸出為  要讓他排序好需在哪些位置插入抹刀
4 3 2 1 5
  <----|   位置 2
1 2 3 4 5

2 5 7 6 4 8
  <--|      位置 4
7 5 2 6 4 8
    <----|  位置 2
4 6 2 5 7 8
<--|        位置 5
6 4 2 5 7 8
   <---|    位置 3
5 2 4 6 7 8
  <--|      位置 4
4 2 5 6 7 8
<--|        位置 5
2 4 5 6 7 8

所以這樣的輸出為
4 3 2 1 5(這裡不能有空格喔)
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
			tmp=i;//紀錄最大值的位置
		}	
	}
	if(tmp!=value-1){
		if(!tmp){//要翻轉的數位於第一個位置
			reverse(line.begin(),line.begin()+value);
			count.push((line.size()-value+1));
		}
		else{//翻轉的數卡在中間
			reverse(line.begin(),line.begin()+tmp+1);//先翻到第一位
			reverse(line.begin(),line.begin()+value);//再翻到正確位置
			count.push((line.size()-tmp));
			count.push((line.size()-value+1));
		}
	}
	if(value-1)
		check(value-1,line,count);//因為要把最大數以前的都先排序好，這樣才是翻最少次的
}
void flip(int value,vector<int> &line,int last,queue<int> &count)
{
	int tmp,i;
	if(value==0){//要翻轉的數位於第一個位置
		reverse(line.begin(),line.begin()+last+1);
		count.push((line.size()-last));
	}
	else{//翻轉的數卡在中間
		check(value,line,count);
		reverse(line.begin(),line.begin()+value+1);//把數翻到第一位
		reverse(line.begin(),line.begin()+last+1);//再翻到正確位置
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
		sort(tmpcake.begin(),tmpcake.end());//tmpcake為已經排序好的
		l=tmpcake.size();
		while(--l>=0){
			tmp=find(tmpcake[l],cakes);//尋找cakes中最大數的位置
			if(tmp!=l)//不在他應該在的位置上
				flip(tmp,cakes,l,count);//翻轉
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
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main()
{
	int box[7],ans,left,tmp;
	while(scanf("%d%d%d%d%d%d",&box[1],&box[2],&box[3],&box[4],&box[5],&box[6]))
	{
		if(box[1]==0&&box[2]==0&&box[3]==0&&box[4]==0&&box[5]==0&&box[6]==0)
			break;
		ans=0;
		ans=box[6];//6X6
		ans+=box[5];//5X5,��box[5]*11��1X1����m
		if(box[1]>box[5]*11)
			box[1]-=box[5]*11;
		else
			box[1]=0;
		ans+=box[4];//4X4
		if(box[2]>=box[4]*5)
			box[2]-=box[4]*5;
		else{
			left=(box[4]*5-box[2])*4;
			box[2]=0;
			if(box[1]>left)
				box[1]-=left;
			else
				box[1]=0;
		}
		ans+=box[3]/4;//3X3
		tmp=box[3]%4;
		if(tmp)
		{
			ans+=1;
			if(tmp==1)
			{
				if(box[2]>=5){
					box[2]-=5;
					left=7;
				}
				else{
					left=(5-box[2])*4+7;
					box[2]=0;
				}
				if(box[1]>left)
					box[1]-=left;
				else
					box[1]=0;
			}
			else if(tmp==2)
			{
				if(box[2]>=3){
					box[2]-=3;
					left=6;
				}
				else{
					left=(3-box[2])*4+6;
					box[2]=0;
				}
				if(box[1]>left)
					box[1]-=left;
				else
					box[1]=0;
			}
			else//(tmp==3)
			{
				if(box[2]>=1){
					box[2]-=1;
					left=5;
				}
				else{
					left=(1-box[2])*4+5;
					box[2]=0;
				}
				if(box[1]>left)
					box[1]-=left;
				else
					box[1]=0;
			}
		}
		if(box[2]!=0)//2X2
		{
			ans+=box[2]/9;
			tmp=box[2]%9;
			if(tmp)
			{
				ans+=1;
				left=36-tmp*4;
				if(box[1]>left)
					box[1]-=left;
				else
					box[1]=0;
			}
		}
		if(box[1]!=0)//1X1
		{
			ans+=box[1]/36;
			tmp=box[1]%36;
			if(tmp)
				ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
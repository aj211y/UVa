//ncku7  鞋店經營  還沒做出成品前會被罰款
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
        int job,cases;
        double fine,day;
        int x=0,a=-1,rec;
        vector<double> ratio;
        vector<double> record;
        scanf("%d",&job);
        rec=job;
        while(job--){
 
                scanf("\n\n%d",&cases);
                if(job!=rec-1)
                        printf("\n");//兩個輸入間有空一行
                a=-1;
                while(cases--){
                        scanf("%lf %lf",&day,&fine);
                        ratio.push_back(fine/day);
                        record.push_back(fine/day);;
                }
                sort(ratio.begin(),ratio.end());//排序
                reverse(ratio.begin(),ratio.end());//由大到小
                while(ratio[++a]!='\0'){
                        for(x=0;x<record.size();x++){
                                if(ratio[a]==record[x]){
                                        printf("%d",x+1);
                                        record[x]=0;//做記號看讀過了沒
                                        if(a!=ratio.size()-1)//如果a不是最後一個
                                                printf(" ");
                                        else{
 
                                                        printf("\n");
                                        }
                                        break;
                                }
                        }
				}	
                ratio.clear();
                record.clear();
        }
        return 0;
}
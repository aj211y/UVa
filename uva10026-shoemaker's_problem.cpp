//ncku7  �c���g��  �٨S���X���~�e�|�Q�@��
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
                        printf("\n");//��ӿ�J�����Ť@��
                a=-1;
                while(cases--){
                        scanf("%lf %lf",&day,&fine);
                        ratio.push_back(fine/day);
                        record.push_back(fine/day);;
                }
                sort(ratio.begin(),ratio.end());//�Ƨ�
                reverse(ratio.begin(),ratio.end());//�Ѥj��p
                while(ratio[++a]!='\0'){
                        for(x=0;x<record.size();x++){
                                if(ratio[a]==record[x]){
                                        printf("%d",x+1);
                                        record[x]=0;//���O����Ū�L�F�S
                                        if(a!=ratio.size()-1)//�p�Ga���O�̫�@��
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
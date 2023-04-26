
#include <stdio.h>
#include <stdlib.h>

typedef struct{
char stnum[12];
int sum;
//int quenum[10];
int score;

}RES;


int main()
{
    int T;//case数
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int N,M,G;
        int s;
        int count=0;//合格人数
        scanf("%d %d %d",&N,&M,&G);//N学生人数，M题目数，G分数线
        RES res[N-1];

        int point[M];
        for(int j=0;j<M;j++)
            scanf("%d",&point[j]);//输入每道题多少分
        for(int k=0;k<N;k++){  //每个人
            res[k].score=0;
            scanf("%s%d",&res[k].stnum,&res[k].sum);
            s=res[k].sum;
            int correct[s];//对的题
            int m=0;
            while(m<res[k].sum){
                scanf("%d",&correct[m]);
                if(correct[m]==0){
                        res[k].score=0;
                        break;
                }
                res[k].score+=point[correct[m]-1];
                m++;
            }
            if(res[k].score>=G)
                count++;
        }
       // qsort(res,N,sizeof(res[0]),cmp);
        printf("case #%d:\n",i);
        printf("%d\n",count);

        int d;
        for(d=0;res[d].score>G&&d<N;d++){
            printf("%s %d\n",res[d].stnum,res[d].score);
        }


    }

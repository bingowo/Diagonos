#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char id[12];
    int grade;
} std;
int cmp(const void*a,const void*b)
{
    std *pa,*pb;
    pa = (std*)a;
    pb = (std*)b;
    if(pa->grade != pb->grade) return pb->grade-pa->grade;
    else return strcmp(pa->id,pb->id);
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int N,M,G,cnt = 0;//学生人数N，题数M，分数线G，过线人数cnt
        scanf("%d%d%d",&N,&M,&G);
        int score[M];
        for(int j=0;j<M;j++){
            scanf("%d",&score[j]);//题目分值
        }
        std L[N];
        for(int j=0;j<N;j++){
            char tmps[12];
            scanf("%s",tmps);
            strcpy(L[j].id,tmps);
            int ACnums;
            scanf("%d",&ACnums);
            while(ACnums--){
                int Qnum;
                scanf("%d",&Qnum);
                L[j].grade += score[Qnum-1];
            }//计算总分
            if(L[j].grade > G) cnt++;
        }
        qsort(L,N,sizeof(std),cmp);
        printf("case #%d:\n%d\n",i,cnt);
        for(int j=0;j<N;j++){
            if(L[j].grade < G) break;
            printf("%s %d\n",L[j].id,L[j].grade);
        }
    }
    return 0;
}

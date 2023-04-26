#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[12];
    int sum;
}student;

int cmp(const void *a,const void *b){
    const student *x = a,*y=b;
    if(x->sum==y->sum){
        return strcmp(x->name,y->name);
    } else{
        return y->sum - x->sum;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        student stu[500];
        int N,M,G;
        scanf("%d %d %d",&N,&M,&G);
        int score[11];
        for(int j=1;j<=M;j++){//输入每题分数
            scanf("%d",&score[j]);
        }
        int cnt=0;//达标总人数
        for(int j=0;j<N;j++){
            int sum=0;//分数总和
            scanf("%s",stu[j].name);
            int n_correct=0;//作对的题目数量
            scanf("%d",&n_correct);
            for(int k=0;k<n_correct;k++){
                int T;//题号
                scanf("%d",&T);
                sum+=score[T];
                stu[j].sum = sum;
            }
            if(sum>=G) cnt++;
        }
        qsort(stu,N,sizeof(stu),cmp);
        printf("case #%d:\n",i);
        printf("%d",cnt);
        for(int j=0;j<cnt;j++){
            printf("%s %d\n",stu[j].name,stu[j].sum);
        }


    }
    return 0;
}
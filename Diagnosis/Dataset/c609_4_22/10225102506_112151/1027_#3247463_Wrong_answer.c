#include <stdio.h>
#include <stdlib.h>

typedef struct stu{
    char num[12];
    int S;
    int T[10];
    int score;
}Stu;

int cmp(const void *a,const void *b){
    Stu* x=(Stu*)a;
    Stu* y=(Stu*)b;
    long long num1=atoi(x->num);
    long long num2=atoi(y->num);
    if(x->score != y->score) return y->score-x->score;
    else{
        if(num1>num2)   return 1;
        else if(num1<num2)  return -1;
        else    return 0;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int N,M,G;
        int point[M+1];
        scanf("%d%d%d",&N,&M,&G);
        for(int j=1;j<=M;j++)
            scanf("%d",&point[j]);
        Stu a[N];
        for(int k=0;k<N;k++){
            a[k].score=0;
            scanf("%s",&a[k].num);
            scanf("%d",&a[k].S);
            for(int l=0;l<a[k].S;l++){
                scanf("%d",&a[k].T[l]);
                a[k].score+=point[a[k].T[l]];
            }
        }
        qsort(a,N,sizeof(Stu),cmp);
        printf("case #%d:\n",i);
        for(int m=0;m<N;m++){
            if(a[m].score>=G)
                printf("%s %d\n",a[m].num,a[m].score);
        }
    }
    return 0;
}

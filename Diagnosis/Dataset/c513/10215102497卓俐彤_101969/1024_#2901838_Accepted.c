#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int compar(const void *a,const void *b);
struct student{
    char number[12];
    int goal;
};

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int N,M,G;
        int sum=0;
        scanf("%d %d %d",&N,&M,&G);
        int score[M+1];
        for(int m=0;m<M;m++)scanf("%d",&score[m]);
        score[M]='\0';
        struct student students[N];
        for(int n=0;n<N;n++)students[n].goal=0;
        for(int n=0;n<N;n++){
            scanf("%s",students[n].number);
            int S;
            scanf("%d",&S);
            for(int s=0;s<S;s++){
                int num;
                scanf("%d",&num);
                students[n].goal+=score[num-1];
            }
            if(students[n].goal>=G)sum++;
        }
        printf("case #%d:\n",t);
        printf("%d\n",sum);
        qsort(students,N,sizeof(students[0]),compar);
        for(int i=0;i<sum;i++)printf("%s %d\n",students[i].number,students[i].goal);
    }
    return 0;
}


int compar(const void*a,const void*b){
    struct student d1,d2;
    d1=*((struct student*)a);
    d2=*((struct student*)b);
    if(d1.goal==d2.goal)return strcmp(d1.number,d2.number);
    else return d2.goal-d1.goal;
}

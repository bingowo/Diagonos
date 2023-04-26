#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char number[12];
    int score;
} STUDENT;

int cmp(const void* p3,const void* p4)
{
    STUDENT* p1=(STUDENT* )p3;
    STUDENT* p2=(STUDENT* )p4;
    if((p1->score)<(p2->score)) return 1;
    else if((p1->score)>(p2->score)) return -1;
    else{
        int w=strcmp(p1->number,p2->number);
        if(w<0) return -1;
        else return 1;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int person=0,all=0,average=0;
        scanf("%d %d %d",&person,&all,&average);
        int* M=(int* )malloc(all*sizeof(int));
        for(int ii=0;ii<all;ii++) scanf("%d",M+ii);
        STUDENT* p=(STUDENT* )malloc(person*sizeof(STUDENT));
        int N=0;
        for(int i=0;i<person;i++){
            char s0[12];
            int correct=0,together=0;
            scanf("%s %d",s0,&correct);
            for(int j=0;j<correct;j++){
                int num=0;
                scanf("%d",&num);
                together+=M[num-1];
            }
            if(together>=average) {
                strcpy((p+N)->number,s0);
                (p+N)->score=together;
                N++;
            }
        }
        qsort(p,N,sizeof(STUDENT),cmp);
        printf("case #%d:\n",t);
        for(int jj=0;jj<N;jj++) printf("%s %d\n",(p+jj)->number,(p+jj)->score);
        free(p);
    }
    return 0;
}

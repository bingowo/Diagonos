#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<malloc.h>
#include<stdlib.h>
struct student{
    char num[12];
    long long int score;
};
int cmp(const void *a,const void *b){
    struct student *m1,*m2;
    m1=(struct student *)a;
    m2=(struct student *)b;
    if(m1->score==m2->score){
        long long int n1,n2;
        n1=atoll(m1->num);
        n2=atoll(m2->num);
        if(n1-n2<0)return -1;
        else return 1;
    }
    else return m2->score-m1->score;
}
int main(){
    int T,c=0;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int N,M,G,people=0;
        scanf("%d%d%d",&N,&M,&G);
        struct student *p;
        p=(struct student *)malloc(N*sizeof(struct student));
        for(int i=0;i<M;i++)(p+i)->score=0;
        long long int *m;
        m=(long long int *)malloc(M*sizeof(long long int));
        for(int i=0;i<M;i++){
            scanf("%d",&*(m+i));
        }
        for(int i=0;i<N;i++){
            int num,d;
            scanf("%s",(p+i)->num);
            scanf("%d",&num);
            while(num-->0){
                scanf("%d",&d);
                (p+i)->score+=m[d-1];
            }
        }
        qsort(p,N,sizeof(struct student),cmp);
        for(int i=0;i<N;i++){
            if((p+i)->score>=G)people++;
        }
        printf("case #%d:\n",c++);
        printf("%d\n",people);
        for(int i=0;i<N;i++){
            if((p+i)->score>G)printf("%s %lld\n",(p+i)->num,(p+i)->score);
        }
        free(p);
        free(m);
    }

}
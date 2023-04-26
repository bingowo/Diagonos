#include <stdio.h>
#include <stdlib.h>

typedef struct data
{
    long long a;
    int number;
}test;

int cmp(const void *a,const void *b)
{
    struct data d1,d2;
    d1=(*(struct data *)a);
    d2=(*(struct data *)b);
    long long int m,n;
    m=d1.a;
    n=d2.a;
    while(d1.a!=0)
    {
        d1.number+=(d1.a&1);
        d1.a>>=1;
    }
    if(d1.a==0)d1.number=0;
    while(d2.a!=0)
    {
        d2.number+=(d2.a&1);
        d2.a>>=1;
    }
    if(d2.a==0)d2.number=0;
    if(d1.number==d2.number)return m-n;
    else return d2.number-d1.number;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++)
    {
        int N;
        scanf("%d",&N);
        test *p=(test*)malloc(N*sizeof(test));
        for(int i=0;i<N;i++)scanf("%lld",&p[i].a);
        qsort(p,N,sizeof(p[0]),cmp);
        printf("case #%d:\n",cas);
        for(int i=0;i<N;i++)printf("%lld ",p[i].a);
        printf("\n");
        free(p);
    }
    return 0;
}

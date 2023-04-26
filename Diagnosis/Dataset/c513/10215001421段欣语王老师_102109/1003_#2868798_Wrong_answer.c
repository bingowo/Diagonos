#include <stdio.h>
#include <stdlib.h>
#define K 10000

struct data
{
    long long int a;
    int number;
};

int cmp(const void *a,const void *b)
{
    struct data d1,d2;
    d1=*((struct data*)a);
    d2=*((struct data*)b);
    if(d2.number!=d1.number)
        return d2.number-d1.number;
    else
    {
        if(d1.a>d2.a)return 1;
        else return -1;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int N;
        printf("case #%d:\n",i);
        scanf("%d",&N);
        struct data p[K];
        for(int m=0;m<N;m++)
        {
        scanf("%lld ",&p[m].a);
        p[m].number=0;
        int d=1;
        for(int l=0;l<64;l++)
        {
            if(p[l].a&d)p[l].number++;
            d=d<<1;
        }
        }
        qsort(p,N,sizeof(p[0]),cmp);
        for(int j=0;j<N-1;j++)
            printf("%lld",p[j].a);
        printf("%lld\n",p[N-1].a);
    }
    return 0;
}

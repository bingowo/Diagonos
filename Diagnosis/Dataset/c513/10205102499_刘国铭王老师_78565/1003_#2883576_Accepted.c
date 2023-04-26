#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct data
{
    long long int a;
    int number;
};

int cmp(const void* a,const void* b)
{
    struct data d1,d2;
    d1=*((struct data*)a);
    d2=*((struct data*)b);
    if(d2.number!=d1.number)
        return d2.number-d1.number;
    else
    {
        if(d1.a > d2.a)
            return 1;
        else
            return -1;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int j=0;j<T;j++)
    {
        int N;
        scanf("%d",&N);
        struct data p[10000];
        for(int i=0;i<N;i++)
        {
            scanf("%lld",&p[i].a);
            long long int d=1;
            p[i].number=0;
            for(int t=0;t<64;t++)
            {
                if(p[i].a & d) p[i].number++;
                d=d<<1;
            }
        }
        qsort(p,N,sizeof(p[0]),cmp);
        printf("case #%d:\n",j);
        for(int k=0;k<N;k++)
            printf("%lld ",p[k].a);
        printf("\n");
    }
    return 0;
}
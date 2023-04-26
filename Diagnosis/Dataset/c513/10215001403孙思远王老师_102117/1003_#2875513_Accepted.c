#include <stdio.h>
#include <stdlib.h>

struct mm
{
    long long int a;
    int b;
};

int cmp(const void *a,const void *b);

int main()
{
    int T,ii;
    scanf("%d",&T);
    for(ii=0;ii<T;ii++)
    {
        int N,j,t;
        printf("case #%d:\n",ii);
        scanf("%d",&N);
        struct mm m[10001];
        int i;
        long long int d;
        for(i=0;i<N;i++)
        {
            scanf("%lld",&m[i].a);
    d=1;m[i].b=0;
    for(t=0;t<64;t++)
     {
         if(m[i].a&d) m[i].b++;
         d=d<<1;

        }}
        qsort(m,N,sizeof(m[0]),cmp);
        for(j=0;j<N-1;j++)
        {
            printf("%lld",m[j].a);
            printf(" ");
        }
        printf("%lld\n",m[j].a);
    }
    return 0;
}

int cmp(const void *a,const void *b)
{
    struct mm d1,d2;
    d1=*((struct mm *)a);
    d2=*((struct mm *)b);
    if(d2.b!=d1.b)
         return d2.b-d1.b;
    else
    {    if(d1.a>d2.a) return 1;
         else return -1;
    }
}


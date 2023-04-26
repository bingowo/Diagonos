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
    int N,T,i,j;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        scanf("%d",&N);
        struct mm m[1000000];
        int ii;
        for(ii=0;ii<N;ii++)
        {
            scanf("%lld",&m[i].a);
    d=1;p[i].number=0;
    for(t=0;t<64;t++)
     {
         if(m[i].a&d) p[i].b++;
         d=d<<1;

        }
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
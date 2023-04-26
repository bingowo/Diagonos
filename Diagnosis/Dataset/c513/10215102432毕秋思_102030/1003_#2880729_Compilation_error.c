#include <stdio.h>
#include <stdlib.h>

struct data
{
    long long int a;
    int number;
};

int cmp(const void*a,const void*b)
{
    struct data d1,d2;
    d1=*((struct data *)a);
    d2=*((struct data *)b);
    if(d2.number!=d1.number)
        return d2.number-d1.number;
    else
    {
        if(d1.a>d2.a) return 1;
        else return -1;
    }
}

int main()
{
    int T,i,j,N,d,t;
    scanf("%d\n",&T);
    for(j=0;j<T;j++)
    {
        struct data p[10000];
        scanf("%d",&N);
        for(i=0;i<N;i++)
        {
            scanf("%lld",&p[i].a);
            d=1;p[i].number=0;
            for(t=0;t<64;t++)
            {
                if(p[i].a&d) p[i].number++;
                d=d<<1;
            }
        }
        qsort(p,n,sizeof(p[0]),cmp);
        printf("case #");
        printf("%d",j);
        printf(":\n");
        for(i=0;i<N-1;i++)
        {
            printf("%lld ",p[i].a);
        }
        printf("%lld\n",p[i].a);
    }
    return 0;
}

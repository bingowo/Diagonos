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
    int T,n,d,i,j,k,t;
    scanf("%d\n",&T);
    for(i=0;i<T;i++)
    {
        struct data p[10000];
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%lld",&p[j].a);
            d=1;p[j].number=0;
            for(t=0;t<64;t++)
            {
                if(p[j].a&d)p[j].number++;
                d=d<<1;
            }
        }
        qsort(p,n,sizeof(p[0]),cmp);
        qsort(p,n,sizeof(p[0]),cmp);
        printf("case #");
        printf("%d",j);
        printf(":\n");
        for(k=0;k<n-1;k++)
        {
            printf("%lld ",p[j].a);
        }
        printf("%lld\n",p[j].a);
    }
    return 0;
}
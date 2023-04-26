#include<stdio.h>
#include<string.h>
#include <stdlib.h>
typedef struct{
    int num;
    long long int a;
}PX;
int cmp2(const void*a,const void*b)
{
    PX c,d;
    c=*(PX*)a;
    d=*(PX*)b;
    if(c.num!=d.num)
       {
           return d.num-c.num;
       }
    else
    {
        if(c.a>d.a) return 1;
        else return -1;
    }
}
int main()
{
    int T;
    PX k[10000];
    scanf("%d",&T);
    for(int j=0;j<T;j++)
    {
        int N;
        scanf("%d",&N);
        for(int q=0;q<N;q++)
        {
            scanf("%lld",&k[q].a);
            int m=1;
            k[q].num=0;
            for(int i=0;i<64;i++)
            {
                if(k[q].a&m)
                {k[q].num++;}
                m=m<<1;
            }
        }
        qsort(k,N,sizeof(k[0]),cmp2);
        printf("case #%d:\n",j);
        for(int t=0;t<N;t++)
        {
            printf("%lld ",k[t].a);
        }
        printf("\n");
    }
    return 0;
}
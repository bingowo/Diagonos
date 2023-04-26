#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
    long long t;
    long long val;
}z;
int cmp(const void *a,const void *b)
{
    long long ta=((z*)a)->t,tb=((z*)b)->t,va=((z*)a)->val,vb=((z*)b)->val;
    if(ta!=tb)return tb-ta;
    else return va-vb;
}
int main()
{
    int T,n;
    scanf("%d",&T);
    for(n=0;n<T;n++)
    {
        int N,i;
        scanf("%d",&N);
        z zs[10001];
        for(i=0;i<N;i++)
        {
            long long value;
            scanf("%lld",&value);
            zs[i].val=value;
            if(value<0)value=-value;
            long long tou=0;
            while(value>0)
            {
                tou=value;
                value/=10;
            }
            zs[i].t=tou;
        }
        qsort(zs,N,sizeof(zs[0]),cmp);
        printf("case #%d:\n",n);
        for(i=0;i<N;i++)
        {
            printf("%lld ",zs[i].val);
        }
        printf("\n");
    }
    return 0;
}

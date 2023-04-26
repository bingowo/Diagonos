#include <stdio.h>
#include <algorithm>
struct data
{
    long long int val;
    int num;
};

int cmp(const void*a,const void*b)
{
    struct data d1,d2;
    d1=*((struct data*)a);
    d2=*((struct data*)b);
    if(d1.num!=d2.num)
        return d2.num-d1.num;
    else
    {
        if(d1.val>d2.val)
            return 1;
        else
            return -1;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int N;
        scanf("%d",&N);
        struct data p[10001];
        for(int j=0;j<N;j++)
        {
            long long int d=1;
            scanf("%lld",&p[j].val);
            p[j].num=0;
            while(p[j].val&&d)
            {
                p[j].num++;
                d=d<<1;
            }
        }
        qsort(p,N,sizeof(p[0]),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<N;j++)
            printf("%lld ",p[j].val);
        printf("\n");
    }
    return 0;
}

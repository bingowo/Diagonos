#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int one;
    long long num;
}bin;

int cmp(const void *q1,const void *q2)
{
    bin *p1=(bin *)q1;
    bin *p2=(bin *)q2;
    if(p1->one > p2->one) return -1;
    if(p1->one < p2->one) return 1;
    if(p1->num > p2->num) return 1;
    else if(p1->num <= p2->num) return -1;
}

int getone(long long a)
{
    int one=0;
    for(int i=0;i<64;i++)
    {
        if((a&((long long)1<<i))==(1LL<<i)){one++;}
    }
    return one;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int N;
        bin arr[10010];
        scanf("%d",&N);
        for (int j=0;j<N;j++)
        {
            scanf("%lld",&arr[j].num);
            arr[j].one=getone(arr[j].num);
        }
        qsort(arr,N,sizeof(bin),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<N-1;j++)
        {
            printf("%lld ",arr[j].num);
        }
        printf("%lld\n",arr[N-1].num);
    }
    return 0;
}

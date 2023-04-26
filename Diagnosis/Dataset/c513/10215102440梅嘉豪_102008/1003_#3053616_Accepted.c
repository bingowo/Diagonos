#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    long long num;
    int ones;
}ONE;
int get_one(long long num);
int cmp(const void* a,const void *b);
int main()
{
    int T,N;
    long long temp;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%d",&N);
        ONE *p;
        p=(ONE*)malloc(sizeof(ONE)*N);
        for(int j=0;j<N;j++)
        {
            scanf("%lld",&temp);
            p[j].num=temp;
            p[j].ones=get_one(temp);
        }
        qsort(p,N,sizeof(ONE),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<N;j++)
        {
            char c=j==N-1?'\n':' ';
            printf("%lld%c",p[j].num,c);
        }
        free(p);
    }
}
// int get_one(long long num)
// {
//     int ones=0;
//     long long b=1;
//     for(int i=0;i<64;i++)
//     {
//         if((b&num)==1)  ones++;
//         num=num>>1;
//     }
//     return ones;
// }
int get_one(long long num)
{
    int ones=0;
    long long b=1;
    for(int i=0;i<64;i++)
    {
        if((b&num)!=0)  ones++;
        b=b<<1;
    }
    return ones;
}

int cmp(const void* a,const void *b)
{
    ONE *pa=(ONE*)a;
    ONE *pb=(ONE*)b;
    if(pa->ones==pb->ones)  return pa->num<pb->num?-1:1;
    return pa->ones>pb->ones?-1:1;
}
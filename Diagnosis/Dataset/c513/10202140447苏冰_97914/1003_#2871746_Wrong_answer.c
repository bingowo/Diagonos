#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int calculate(long long n)
{
    int cnt=0;
    for(int i=1;i<=64;i++)
    {
       cnt+=n&1;
       n=n>>1;
    }
    return cnt;
}
typedef struct S
{
    int num;
    long long di;
}s;
int cmp(const void*_a,const void*_b)
{
    s* a=(s*)_a;
    s* b=(s*)_b;
    if(a->num==b->num)
    {
        return (a->di)-(b->di);
    }
    return (b->num)-(a->num);
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        int N;
        scanf("%d",&N);
        s s1[N];
        for(int j=0;j<N;j++)
        {
            scanf("%lld",&s1[j].di);
            s1[j].num=calculate(s1[j].di);
        }
        qsort(s1,N,sizeof(s),cmp);
        printf("case #%d:\n",i-1);
       for(int j=0;j<N;j++)
       {
           printf("%lld ",s1[j].di);
       }
       printf("\n");
    }

    return 0;
}

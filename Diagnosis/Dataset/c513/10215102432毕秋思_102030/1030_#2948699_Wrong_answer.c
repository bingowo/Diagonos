#include<stdio.h>
#include<math.h>

struct DATA
{
    int a;
    long long b;
}data[10010];

long long cmp(const void *q1,const void *q2)
{
    struct DATA *p1=(struct DATA*)q1;
    struct DATA *p2=(struct DATA*)q2;
    if(p1->a<p2->a) return 1;
    else if(p1->a>p2->a) return -1;
    else if(p1->a==p2->a)
    {
        if(p1->b>p2->b) return 1;
        else return -1;
    }
}

int first(long long x0)
{
    long long x=abs(x0);
    while(x>=10)
    {
        x/=10;
    }
    return x;
}

int main()
{
    int T;
    scanf("%d\n",&T);
    for(int t=0;t<T;t++)
    {
        int n=0;
        scanf("%d\n",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&data[i].b);
            data[i].a=first(data[i].b);
        }

        qsort(data,n,sizeof(struct DATA),cmp);

        printf("case #%d:\n",t);
        int j;
        for(j=0;j<n-1;j++)
            printf("%lld ",data[j].b);
        printf("%lld\n",data[j].b);
    }
    return 0;
}

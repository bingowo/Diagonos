#include <stdio.h>

struct data
{
    long long int a;
    int number;
};

int cmp(const void *a,const void *b)
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
    struct data p[10000];
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        printf("case #%d:\n",i);
        int n;
        scanf("%d",&n);
        for(int j=0;j<n;j++)
        {
            scanf("%lld",&p[j].a);
            long long int d=1;
            p[j].number=0;
            for(int k=0;k<64;k++)
            {
                if(p[j].a&d) p[j].number++;
                d=d<<1;
            }
        }
        qsort(p,n,sizeof(p[0]),cmp);
        for(int x=0;x<n-1;x++)
            printf("%lld ",p[x].a);
        printf("%lld\n",p[n-1].a);
    }
    return 0;
}

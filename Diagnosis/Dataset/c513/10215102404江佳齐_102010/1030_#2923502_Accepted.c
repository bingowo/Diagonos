#include <stdio.h>
#include <stdlib.h>

struct SSS
{
    int first;
    long long int d;
};
int cmp(const void *a, const void *b)
{
    struct SSS s1,s2;
    s1=*((struct SSS*)a);
    s2=*((struct SSS*)b);
    if(s1.first!=s2.first) return s2.first-s1.first;
    else
    {
        if(s1.d>s2.d) return 1;
        else return -1;
    }
}

int main()
{
    int T;
    struct SSS a[10000];
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int N;
        scanf("%d",&N);
        for(int j=0;j<N;j++)
        {
            long long int m;
            scanf("%lld ",&a[j].d);
            if(a[j].d<0) m=-a[j].d;
            else m=a[j].d;
            while(m>=10)
            {
                m=m/10;
            }
            a[j].first=m;
        }
        qsort(a,N,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        int k;
        for(k=0;k<N-1;k++) printf("%lld ",a[k].d);
        printf("%lld\n",a[k].d);
    }
    return 0;
}

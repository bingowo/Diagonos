#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
typedef struct SSS
{
    long long value;
    int cnt;
} sss;
int cmp(const void*_a,const void*_b)
{
    sss*a=(sss*)_a;
    sss*b=(sss*)_b;
    if(a->cnt != b->cnt)
    {
        return (b->cnt)-(a->cnt);
    }
    else return (a->value)>(b->value)?1:-1;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=0; cas<T; cas++)
    {
        int n;
        scanf("%d",&n);
        sss a[n];
        for(int i=0; i<n; i++)
        {
            long long x=0;
            scanf("%lld",&x);
            a[i].value=x;
            int cnt=0;
            for(int j=0; j<64; j++)
            {
                if(x&1) cnt++;
                x=x>>1;
            }
            a[i].cnt=cnt;
        }
        qsort(a,n,sizeof(sss),cmp);
        printf("case #%d:\n",cas);
        for(int i=0; i<n; i++)
        {
            printf("%lld ",a[i].value);
        }
        printf("\n");
    }
    return 0;
}


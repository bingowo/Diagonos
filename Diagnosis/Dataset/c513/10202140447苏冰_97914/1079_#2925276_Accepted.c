#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
long long  a[1005]={0};
long long b[500505]={0};
int cmp(const void*p,const void*q)
{
    long long* a=(long long*)p;
    long long* b=(long long*)q;
    return(*a>*b?1:-1);
}
int main()
{
    int T;
    scanf("%d",&T);
    int n,m,l,u;
    for(int cas=0;cas<T;cas++)
    {
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            a[i]=a[i]+a[i-1];
        }
        int k=0;
        for(int len=1;len<=n;len++)
        {
            for(int i=1;i<=n-len+1;i++)
            {
                b[++k]=a[i+len-1]-a[i-1];
            }
        }
        qsort(b+1,k,sizeof(b[0]),cmp);
        for(int i=1;i<=k;i++) b[i]+=b[i-1];
         printf("case #%d:\n",cas);
        for(int i=0;i<m;i++)
        {
            scanf("%d %d",&l,&u);
            printf("%lld\n",b[u]-b[l-1]);
        }
    }
    return 0;
}

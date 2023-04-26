#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>

int cmp(const void*a,const void*b)
{
    long long a1=*(long long*)a;
    long long b1=*(long long*)b;
    return a1>b1?1:-1;
}

int main()
{
    int T,m,n,L,U;
    long long ans=0;
    scanf("%d",&T);
    for(int i=0;i<T;++i)
    {
        scanf("%d%d",&n,&m);
        long long*a=(long long*)malloc(sizeof(long long)*n*(n+1)/2);
        for(int j=0;j<n;++j)
        {
            scanf("%lld",&a[j]);
        }
        for(int j=1;j<n;++j)
        {
            int idx=j*n-j*(j-1)/2;
            for(int k=0;idx<n*(j+1)-(j+1)*j/2;++idx,++k)
            {
                a[idx]=a[k]+a[idx-n+j];
            }
        }
        qsort(a,n*(n+1)/2,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<m;++j)
        {
            scanf("%d%d",&L,&U);
            if(L==U) ans=a[L-1];
            else
            {
                for(int k=L-1;k<U;++k)
                {
                    ans+=a[k];
                }
            }
            printf("%lld\n",ans);
            ans=0;
        }
    }
    return 0;
}

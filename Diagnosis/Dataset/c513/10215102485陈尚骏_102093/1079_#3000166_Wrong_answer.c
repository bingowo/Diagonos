#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>

int cmp(const void*a,const void*b)
{
    long long a1=*(long long*)a;
    long long b1=*(long long*)b;
    if(a1>b1) return 1;
    else return -1;
}

int main()
{
    int T,n,m,L,U;
    long long ans=0;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%d %d",&n,&m);
        long long*a=(long long*)malloc(sizeof(long long)*n*(n+1)/2);
        for(int j=0;j<n;j++)
            scanf("%lld",&a[j]);
        for(int j=1;j<n;j++)
        {
            int idx=j*n+j*(j-1)/2;
            for(int k=0;idx<(j+1)*n-(j+1)*j/2;idx++,k++)
            {
                a[idx]=a[k]+a[idx-n+j];
            }
        }
        qsort(a,n*(n+1)/2,sizeof(ans),cmp);
        printf("case #%d:\n",i);
        for(int k=0;k<m;k++)
        {
            scanf("%d %d",&L,&U);
            if(L==U) ans=a[L-1];
            else
            {
                for(int j=L-1;j<=U-1;j++) ans+=a[j];
            }
            printf("%lld\n",ans);
            ans=0;
        }
    }
    return 0;
}

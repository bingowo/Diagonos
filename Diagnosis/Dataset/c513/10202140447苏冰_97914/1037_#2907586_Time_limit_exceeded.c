#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <limits.h>
long long a[1000010];
int cmp(const void* p,const void* q)
{
    long long* a=(long long*)p;
    long long* b=(long long*)q;
    return( (*a>*b) ? -1 : 1);
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    long long ans=0;long long min=LLONG_MAX;
    for(int i=0;i<=n-m;i++)
    {
        ans=0;
        long long max=a[i];
        for(int j=i+1;j<i+m;j++)
        {
            ans=ans+(max-a[j]);
        }
        if(ans<=min)
        {
            min=ans;
        }
    }
    printf("%lld",min);
    return 0;
}

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
    for(int i=1;i<m;i++) ans=ans+(a[0]-a[i]);
    if(ans<=min) min=ans;
    for(int i=1;i<=n-m;i++)
    {
         ans=ans-(m-1)*a[i-1]+a[i]*m-a[i+m-1];
        if(ans<=min)
        {
            min=ans;
        }
    }
    printf("%lld",min);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void*_a,const void*_b)
{
    long long* a=(long long*)_a;
    long long* b=(long long*)_b;
    return ((*a) > (*b) ? 1 : -1);
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    long long cnt=0;
    long long a[1000010];
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        cnt+=a[i];
    }
    qsort(a,n,sizeof(a[0]),cmp);
    long long ans=0;
    for(int i=0;i<=n-m;i++)
    {
        for(int j=i;j<i+m-1;j++)
        {
             ans+=a[i+m-1]-a[j];
        }
        if(cnt>=ans) cnt=ans;
    }
    printf("%lld",cnt);
    return 0;
}

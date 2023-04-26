#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void*_a,const void*_b)
{
    long long* a=(long long*)_a;
    long long* b=(long long*)_b;
    return (*a > *b ?1:-1);
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    long long a[1000010];
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    long long ans=a[m-1]*(m-1);
    for(int i=0;i<m-1;i++)
    {
        ans-=a[i];
    }
    printf("%lld",ans);
    return 0;
}

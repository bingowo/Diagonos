#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int cmp(const void*_a,const void*_b)
{
    int* a=(int*)_a;
    int* b=(int*)_b;
    return(*a - *b);
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[1000000];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    long long ans=0;
    for(int i=0;i<n-1;i+=2)
    {
        ans+=a[i+1]-a[i];
    }
    printf("%lld",ans);
    return 0;
}

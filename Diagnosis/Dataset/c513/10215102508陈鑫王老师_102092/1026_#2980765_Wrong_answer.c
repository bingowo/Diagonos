#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b)
{
    int*x=(int *)a;
    int*y=(int *)b;
    return a>b?1:-1;
}
int main()
{
    int n;
    scanf("%d",&n);
    long long int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    qsort(a,n,sizeof(long long int),cmp);
    long long int ans=0;
    for(int i=0;i<n-1;i+=2)
    {
        ans+=a[i+1]-a[i];
    }
    printf("%lld",ans);
    return 0;
}

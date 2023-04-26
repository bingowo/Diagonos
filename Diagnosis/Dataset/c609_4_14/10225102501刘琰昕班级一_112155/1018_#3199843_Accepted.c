#include <stdio.h>
#include <stdlib.h>

int cmp(long long *a,long long *b){return (*a-*b)<0?-1:1;}

int main()
{
    int n;scanf("%d",&n);
    long long *a;a=(long long *)malloc(n*sizeof(long long));
    for(int i=0;i<n;i++)scanf("%lld",&a[i]);
    qsort(a,n,sizeof(long long),cmp);
    long long ans=0;
    for(int i=1;i<n;i+=2)ans+=a[i]-a[i-1];
    printf("%d",ans);
}

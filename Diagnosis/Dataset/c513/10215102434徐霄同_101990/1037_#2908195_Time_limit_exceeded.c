#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    if(*(long long*)b>*(long long*)a)
        return 1;
    else
        return -1;
}
int main()
{
    long long m,n,i,j,x,s;
    long long a[1000000];
    scanf("%lld%lld",&n,&m);
    for(i=0;i<n;i++)
        scanf("%lld",&a[i]);
    qsort(a,n,sizeof(a[0]),cmp);
    x=0;
    for(i=1;i<m;i++)
        x=x+(a[0]-a[i]);
    for(i=1;i<n-m+1;i++){
        s=0;
        for(j=i+1;j<i+m;j++)
            s=s+(a[i]-a[j]);
        if(s<x)
            x=s;
    }
    printf("%lld\n",x);
    return 0;
}

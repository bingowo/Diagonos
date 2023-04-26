#include <stdio.h>
#include<string.h>
#include<math.h>
int cmp(const void*a,const void *b)
{
    long long a0=*(long long*)a,b0=*(long long*)b,na=0,nb=0,n=1;
    while(n)
    {
        if(a0&n)na++;
        n<<=1;
    }
    n=1;
    while(n)
    {
        if(b0&n)nb++;
        n<<=1;
    }
    if(na==nb)return a0>b0?1:-1;
    return na>nb?-1:1;
}
int main() {
    long long x,y,i,n,j,a[10000];
    scanf("%lld",&x);
    for(i=0;i<x;i++)
    {
        scanf("%lld",&y);
        for(j=0;j<y;j++)
        {
            scanf("%lld",&a[j]);
        }
        qsort(a,y,sizeof(a[0]),cmp);
        printf("case #%lld:\n",i);
        for(j=0;j<y-1;j++)printf("%lld ",a[j]);
        printf("%lld\n",a[j]);
    }
    return 0;
}

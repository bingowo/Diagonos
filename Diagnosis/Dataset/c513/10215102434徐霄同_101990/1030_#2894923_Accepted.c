#include <stdio.h>
#include <stdlib.h>
int zgw(long long x)
{
    while(x/10!=0)
        x=x/10;
    if(x<0)
        x=-x;
    return x;
}
int cmp(const void *a,const void *b)
{
    long long a0=*(long long*)a;
    long long b0=*(long long*)b;
    if(zgw(a0)!=zgw(b0))
        return zgw(b0)-zgw(a0);
    else if(a0>b0)
        return 1;
    else
        return -1;
}
int main()
{
    int t,n,i,j;
    long long a[10000];
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d",&n);
        for(j=0;j<n;j++)
            scanf("%lld",&a[j]);
        qsort(a,n,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<n;j++){
            printf("%lld",a[j]);
            if(j==n-1)
                printf("\n");
            else
                printf(" ");
        }
    }
    return 0;
}

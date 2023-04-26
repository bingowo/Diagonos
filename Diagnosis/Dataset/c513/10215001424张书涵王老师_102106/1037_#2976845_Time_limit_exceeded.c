#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a,const void*b)
{
    long long int *ap=(long long int*)a;
    long long int *bp=(long long int*)b;
    if(*ap>*bp)
        return -1;
    else
        return 1;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    long long int *a;
    a=(long long int*)calloc(n,sizeof(long long int));
    int i;
    for(i=0;i<n;i++)
        scanf("%lld",a+i);
    qsort(a,n,sizeof(long long int),cmp);
    int j;
    long long int total=0,amount=0;
    for(i=1;i<m;i++)
    {
        amount=amount+a[i];
    }
    amount=(m-1)*a[0]-amount;
    for(j=1;j<=(n-m);j++)
    {
        total=(m-1)*a[j];
        for(i=j+1;i<(j+m);i++)
            total=total-a[i];
        amount=(total>amount)?amount:total;
    }
    printf("%lld",amount);
}
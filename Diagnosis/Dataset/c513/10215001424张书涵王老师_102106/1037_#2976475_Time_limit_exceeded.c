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
    long long int total=0,amount;
    for(j=1;j<=(m-1);j++)
        total=total+*a-*(a+j);
    for(i=1;i<n;i++)
    {
        amount=0;
        j=i+1;
        if(j==(n-m+2))
            break;
        for(;j<=(i+m-1);j++)
        {
            amount=amount+*(a+i)-*(a+j);
        }
        total=(total>amount)?amount:total;
    }
    printf("%lld",total);
}
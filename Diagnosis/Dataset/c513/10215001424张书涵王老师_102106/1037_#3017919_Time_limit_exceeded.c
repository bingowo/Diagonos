#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a,const void*b)
{
    long long int *ap=(long long int*)a;
    long long int *bp=(long long int*)b;
    if(*ap>*bp)
        return 1;
    else
        return -1;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    long long int *a;
    a=(long long int *)calloc(n,sizeof(long long int));
    int i;
    for(i=0;i<n;i++)
        scanf("%lld",&a[i]);
    qsort(a,n,sizeof(long long int),cmp);
    int j;
    long long int total=0,amount;
    for(i=0;i<m;i++)
        total=total+a[m-1]-a[i];
    for(i=1;i<(n-m+1);i++)
    {
        amount=0;
        for(j=i;j<=(m+i-1);j++)
        {
            amount=amount+a[m+i-1]-a[j];
            if(amount>total)
                break;
        }
        if(amount<=total)
            total=amount;
    }
    printf("%lld",total);
    free(a);
}
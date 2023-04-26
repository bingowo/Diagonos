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
    double *a;
    a=(double *)calloc(n,sizeof(double));
    int i;
    for(i=0;i<n;i++)
        scanf("%lf",&a[i]);
    qsort(a,n,sizeof(double),cmp);
    int j;
    double total=0,amount;
    for(j=1;j<=(m-1);j++)
        total=total+a[0]-a[j];
    for(i=1;i<(n-m+1);i++)
    {
        amount=0;
        j=i+1;
        for(;j<=(i+m-1);j++)
        {
            amount=amount+a[i]-a[j];
        }
        total=(total>amount)?amount:total;
    }
    printf("%.0lf",total);
    free(a);
}
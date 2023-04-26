#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a,const void*b)
{
    double *ap=(double*)a;
    double *bp=(double*)b;
    if(*ap>*bp)
        return 1;
    else
        return -1;
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
    printf("%.0lf",total);
    free(a);
}

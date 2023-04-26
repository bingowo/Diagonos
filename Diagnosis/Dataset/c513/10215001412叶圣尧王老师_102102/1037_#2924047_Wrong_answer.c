#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int cmp(long long*a,long long*b)
{
    return *b-*a;
}

int main()
{
    int n,i,j,m;long long *a=malloc(1000000*sizeof(long long int)),sum,max;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%lld",&a[i]);
    qsort(a,n,sizeof(long long int),cmp);
    for(i=0;i<n;i++)
    {
        sum=0;
        for(j=i+1;j<i+m+1;j++)sum+=llabs(a[i]-a[j]);
        max=max>sum?max:sum;
    }
    printf("%lld",max);
}
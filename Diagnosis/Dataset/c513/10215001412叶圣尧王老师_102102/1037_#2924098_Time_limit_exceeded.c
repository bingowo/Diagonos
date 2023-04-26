#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int cmp(const void*a,const void*b)
{
    return *(long long*)a<*(long long*)b;
}

int main()
{
    int n,i,j,m;long long *a=malloc(1000000*sizeof(long long int)),sum,min;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%lld",&a[i]);
    qsort(a,n,sizeof(long long int),cmp);
    for(i=0;i<n-m+1;i++)
    {
        sum=0;
        for(j=i+1;j<i+m;j++)sum+=llabs(a[i]-a[j]);
        if(i==0)min=sum;
        else min=min>sum?sum:min;
    }
    free(a);
    printf("%lld",min);
}

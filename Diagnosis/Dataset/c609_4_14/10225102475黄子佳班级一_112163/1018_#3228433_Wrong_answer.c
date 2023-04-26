#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
    long long int m=*((long long int *)a);
    long long int n=*((long long int *)b);
    return n-m;   //降序
}

int main()
{
    int n;
    scanf("%d",&n);
    int *p;
    p=(int *)malloc(10000*sizeof(long long int));
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&p[i]);
    }
    qsort(p,n,sizeof(long long int),cmp);
    long long int sum=0;
    for(int i=0;i<n-1;i++)
    {
        sum=sum+(p[i]-p[i+1]);
        i++;
    }
    printf("%lld",sum);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
    long long int m=*((long long int *)a);
    long long int n=*((long long int *)b);
    if(m<n)return 1;
    if(m>n)return -1;
    if(m==n)return 0;   //降序
}

int main()
{
    long long int n;
    scanf("%lld",&n);
    long long int *p;
    p=(long long int *)malloc(100000*sizeof(long long int));
    for(long long int i=0;i<n;i++)
    {
        scanf("%lld",&p[i]);
    }
    qsort(p,n,sizeof(long long int),cmp);
    long long int sum=0;
    for(long long int i=0;i<n-1;i++)
    {
        sum=sum+(p[i]-p[i+1]);
        i++;
    }
    printf("%lld",sum);
    free(p);
    return 0;
}
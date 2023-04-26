#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int cmp(const void* p,const void* q)
{
    long long* a=(long long*)p;
    long long* b=(long long*)q;
    return( (*a>*b) ? -1 : 1);
}
int main()
{
    long long int n,m,i;
    scanf("%lld %lld",&n,&m);
    long long int *s=(long long int *)malloc(sizeof(long long int)*n);
    for(i=0;i<n;i++)
    {
        long long int temp;
        scanf("%lld",&temp);
        s[i]=temp;
    }
    qsort(s,n,sizeof(s[0]),cmp);
    long long int *p=(long long int *)malloc(sizeof(long long int)*(n-1));
    for(i=0;i<n-1;i++)
    {
        p[i]=s[i]-s[i+1];
    }
    long long int sum=0;
    for(i=0;i<m-1;i++)
    {
        sum+=p[i]*(m-i-1);
    }
    long long int min=sum;
    for(i=0;i<n-m;i++)
    {
        sum-=p[i]*(m-1);
        sum+=(s[i+1]-s[i+m]);
        if(sum<min) min=sum;
    }
    printf("%lld\n",min);
    free(s);s=NULL;
    free(p);p=NULL;
    return 0;
}


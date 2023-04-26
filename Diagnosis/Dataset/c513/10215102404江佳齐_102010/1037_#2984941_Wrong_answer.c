#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int cmp(const void *a,const void *b)
{
    long long int s1,s2;
    s1=*((long long int *)a);
    s2=*((long long int *)b);
    return s2-s1;
}
int main()
{
    int n,m,i;
    scanf("%d %d",&n,&m);
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
    return 0;
}


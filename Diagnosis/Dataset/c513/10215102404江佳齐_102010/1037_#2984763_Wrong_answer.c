#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    long long int s1,s2;
    s1=*((long long int *)a);
    s2=*((long long int *)b);
    return s2-s1;
}
int main()
{
    int n,m,i,j;
    long long int s[100000];
    long long int sum[1000000];
    scanf("%d %d",&n,&m);
    int d=n-m;
    for(i=0;i<n;i++) scanf("%lld",&s[i]);
    qsort(s,n,sizeof(s[0]),cmp);
    for(i=0;i<=d;i++)
    {
        sum[i]=(m-1)*s[i];
        for(j=i+1;j<i+m;j++) sum[i]=sum[i]-s[j];
    }
    qsort(sum,d+1,sizeof(sum[0]),cmp);
    printf("%lld\n",sum[d]);
    return 0;
}


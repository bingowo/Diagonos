#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b)
{
    long long int d1,d2;
    int t;
    d1=*((long long int*)a),d2=*((long long int*)b);
    if(d1>d2) t=-1;
    else t=1;
    return t;
}

int main()
{
    long long int n,m;
    scanf("%lld%lld",&n,&m);
    long long int num[n],i,j;
    for(i=0;i<n;i++)
        scanf("%lld",&num[i]);
    qsort(num,n,sizeof(num[0]),cmp);
    long long int mid[n];
    for(i=0;i<=n-m;i++)
    {
        mid[i]=0;
        for(j=i;j<i+m;j++)
            mid[i]+=num[i]-num[j];
    }
    qsort(mid,n-m+1,sizeof(mid[0]),cmp);
    printf("%lld",mid[n-m]);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b)
{
    unsigned long long int d1,d2;
    int t;
    d1=*((unsigned long long int*)a),d2=*((unsigned long long int*)b);
    if(d1>d2) t=-1;
    else t=1;
    return t;
}

int main()
{
    unsigned long long int n,m;
    scanf("%llu%llu",&n,&m);
    unsigned long long int num[n],i,j;
    for(i=0;i<n;i++)
        scanf("%llu",&num[i]);
    qsort(num,n,sizeof(num[0]),cmp);
    unsigned long long int mid[n];
    for(i=0;i<=n-m;i++)
    {
        mid[i]=0;
        for(j=i;j<i+m;j++)
            mid[i]+=num[i]-num[j];
    }
    qsort(mid,n-m+1,sizeof(mid[0]),cmp);
    printf("%llu",mid[n-m]);
    return 0;
}

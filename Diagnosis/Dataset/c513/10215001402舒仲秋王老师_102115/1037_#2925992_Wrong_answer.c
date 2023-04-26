#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b)
{
    long int d1,d2;
    int t;
    d1=*((long int*)a),d2=*((long int*)b);
    if(d1>d2) t=-1;
    else t=1;
    return t;
}

int main()
{
    long int n,m;
    scanf("%ld%ld",&n,&m);
    long int num[n],i,j;
    for(i=0;i<n;i++)
        scanf("%ld",&num[i]);
    qsort(num,n,sizeof(num[0]),cmp);
    long int mid[n];
    for(i=0;i<n-m;i++)
    {
        mid[i]=0;
        for(j=i;j<i+m;j++)
            mid[i]+=num[i]-num[j];
    }
    qsort(mid,n-m,sizeof(mid[0]),cmp);
    printf("%ld",mid[n-m-1]);
    return 0;
}

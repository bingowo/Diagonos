#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int cmp(const void* a,const void* b)
{
    long long int m=*(long long int*)a;
    long long int n=*(long long int*)b;
    if(m<n)
        return 1;
    else
        return -1;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    long long int res[n];
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&res[i]);
    }
    qsort(res,n,sizeof(res[0]),cmp);
    long long int sum=0;
    long long int min=100000000000;
    for(int j=0;j<n-m+1;j++)
    {
        sum=0;
        int k=j;
        for(;k<j+m;k++)
        {
            sum=sum+res[j]-res[k];
        }
        if(sum<min)
            min=sum;
    }
    printf("%lld\n",min);
    return 0;
}
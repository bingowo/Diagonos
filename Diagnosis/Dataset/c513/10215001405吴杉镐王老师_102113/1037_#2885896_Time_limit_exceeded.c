#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int cmp(const void* a,const void* b)
{
    unsigned long long int m=*(unsigned long long int*)a;
    unsigned long long int n=*(unsigned long long int*)b;
    if(m<n)
        return 1;
    else
        return -1;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    unsigned long long int res[n];
    for(int i=0;i<n;i++)
    {
        scanf("%llu",&res[i]);
    }
    qsort(res,n,sizeof(res[0]),cmp);
    unsigned long long int sum=0;
    unsigned long long int min=9223372036854775807;
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
    printf("%llu\n",min);
    return 0;
}

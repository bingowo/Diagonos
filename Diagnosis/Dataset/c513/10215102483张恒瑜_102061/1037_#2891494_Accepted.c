#include<stdio.h>
#include<stdlib.h>

int cmp(const void* a, const void* b)
{
    return *(long long*)a>*(long long*)b ? -1:1 ;
}
int main()
{
    long long i,n,m;
    scanf("%lld %lld",&n,&m);
    long long input[n];
    for(i=0;i<n;i++) scanf("%lld",&input[i]);
    qsort(input,n,sizeof(input[0]),cmp);
    long long min,tmp=0;
    for(i=0;i<m;i++)
    {
        tmp+=input[0]-input[i];
    }
    min=tmp;
    for(i=m;i<n;i++)
    {
        tmp=tmp-input[i-m]*(m-1)+input[i-m+1]*m-input[i];
        if(tmp<min) min=tmp;
    }
    printf("%lld",min);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>

int cmp1(const void* a, const void* b)
{
    return *(long long*)a>*(long long*)b ? -1:1 ;
}
int main()
{
    long long i,n,m;
    scanf("%lld %lld",&n,&m);
    long long input[n];
    for(i=0;i<n;i++) scanf("%lld",&input[i]);
    qsort(input,n,sizeof(input[0]),cmp1);
    long long min;
    for(i=0;i<=n-m;i++)
    {
        long long j,tmp=0;
        for(j=0;j<m;j++)
        {
            tmp+=input[i]-input[j+i];
            if(tmp>=min && i!=0) break;
        }
        if(i==0) min=tmp;
        if(tmp<min) min=tmp;
    }
    printf("%lld",min);
    return 0;
}
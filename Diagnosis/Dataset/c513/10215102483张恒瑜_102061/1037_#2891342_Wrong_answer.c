#include<stdio.h>
#include<stdlib.h>

int cmp(const void* a, const void* b)
{
    return *(long long*)a>*(long long*)b ? -1:1 ;
}
int main()
{
    int i,n,m;
    scanf("%d %d",&n,&m);
    long long input[n];
    for(i=0;i<n;i++) scanf("%lld",&input[i]);
    qsort(input,n,sizeof(input[0]),cmp);
    long long min=1000000000000;
    for(i=0;i<=n-m;i++)
    {
        int j;
        long long tmp=0;
        for(j=0;j<m;j++)
        {
            tmp+=input[i]-input[j+i];
        }
        if(tmp<min) min=tmp;
    }
    printf("%lld",min);
    return 0;
}
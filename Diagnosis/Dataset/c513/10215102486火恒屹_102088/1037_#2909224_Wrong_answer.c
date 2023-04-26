#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    return(*(long long*)a-*(long long*)b);
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    long long num[1000001]={0};
    for(int i=0;i<n;i++)
        scanf("%lld",&num[i]);
    qsort(num,n,sizeof(num[0]),cmp);
    long long sum=m*num[m-1];
    for(int i=0;i<m-1;i++)
        sum=sum-num[i];
    long long gap=0;
    for(int i=m;i<n;i++)
    {
        gap=m*(num[i]-num[i-1])-num[i-1]+num[i-m];
        if(gap<0)
            sum=sum+gap;
    }
    printf("%lld",sum);
    return 0;
}

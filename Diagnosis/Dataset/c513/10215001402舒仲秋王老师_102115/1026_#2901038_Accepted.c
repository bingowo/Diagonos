#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b)
{
    int d1,d2;
    d1=*((long long int*)a),d2=*((long long int*)b);
    return d1-d2;
}

int main()
{
    long long int n,num[100000],i;
    scanf("%lld",&n);
    for(i=0;i<n;i++) scanf("%lld",&num[i]);
    qsort(num,n,sizeof(num[0]),cmp);
    long long int sum=0;
    for(i=0;i<n;i+=2) sum+=num[i+1]-num[i];
    printf("%lld",sum);
    return 0;
}

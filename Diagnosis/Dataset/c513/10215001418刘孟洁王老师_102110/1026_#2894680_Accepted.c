#include <stdio.h>
#include <stdlib.h>
#define N 100000
int compare(const void*a,const void*b)
{
    long long int c=*(long long int*)a;
    long long int d=*(long long int*)b;
    if(c>d)return 1;
    else if(c<=d)return -1;
}

int main()
{
    int i,n;
    long long int s[N],sum;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%lld",&s[i]);
    qsort(s,n,sizeof(s[0]),compare);
    for(i=0,sum=0;i<n-1;i+=2)
        sum=sum+s[i+1]-s[i];
    printf("%lld",sum);
    return 0;
}

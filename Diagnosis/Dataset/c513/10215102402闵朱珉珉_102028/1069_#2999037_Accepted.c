#include <stdio.h>
#include <stdlib.h>
int t=0;
long long put(long long n)
{
    long long N[100],flag=0;
    int i=0;
    long long num=n,q=0;
    for(;num>0;i++)
    {
        N[i]=num%10;
        num/=10;
    }
    for(int j=0;j<i;j++)
        if(N[j]!=N[i-1-j]) flag=1;
    if(flag==0) return n;
    t++;
    for(int j=0;j<i;j++)
        q=q*10+N[j];
    return put(n+q);
}

int main()
{
    long long n;
    scanf("%lld",&n);
    printf("%d %lld",t,put(n));
    return 0;
}

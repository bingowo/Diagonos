#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 50
long long f(int n)
{
    static long long m[N];
    if(n<0) return 0;
    if(n==0) m[n]=1;
    else
    {
        if(m[n]==0) m[n]=f(n-1)+f(n-2)+f(n-3)+f(n-4);
    }
    return m[n];
}
int main()
{
    long long n;
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%lld",&n);
        n=f(n);
        printf("case #%d:\n%lld\n",i,n);
    }
    return 0;
}

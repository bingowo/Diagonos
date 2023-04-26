#include <stdio.h>

void trans(long long n)

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        long long n;
        scanf("%lld",&n);
        if(n==0)printf("0");
        else trans(n);
        printf('\n');
    }
}

void trans(long long n)
{
    if(n>0)
    {
        f(n/2233);
        printf("%d", n%2233);
    }
}
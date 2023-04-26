#include <stdio.h>
#include <stdlib.h>
#include<string.h>

long long GCD(long long a,long long b)
{
    return a%b==0?b:GCD(b,a%b);
}

long long field(long long x,long long y)
{
    long long t=GCD(x,y);
    x/=t;y/=t;
    if(x==y)return 4*x*t;
    else{
        return (4*y+field(y,x-y))*t;
    }
}

int main()
{
    long long a,b;
    scanf("%lld%lld",&a,&b);
    long long ret=field(a,b);
    printf("%lld",ret);
    return 0;
}

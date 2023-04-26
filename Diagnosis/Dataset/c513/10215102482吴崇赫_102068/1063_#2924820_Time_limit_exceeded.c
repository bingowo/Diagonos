#include <stdio.h>
#include <stdlib.h>
#include<string.h>

long long GCD(long long a,long long b)
{
    return a%b==0?b:GCD(b,a%b);
}

long long field(long long x,long long y)
{
    if(x==y)return 4*x;
    else{
        if(x<y){long long temp=x;x=y;y=temp;}
        return 4*y+field(y,x-y);
    }
}

int main()
{
    long long a,b;
    scanf("%lld%lld",&a,&b);
    long long t=GCD(a,b);
    long long ret=field(a/t,b/t);
    printf("%lld",ret*t);
    return 0;
}

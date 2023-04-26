#include <stdio.h>
#include <stdlib.h>

long long int num(long long int a,long long int b)
{
    if(a==b) return 4*a;
    else if(a>b)
        return 4*b+num(b,a-b);
    else if(a<b)
        return 4*a+num(b,b-a);
}

int main()
{
    long long int a,b;
    scanf("%lld %lld",&a,&b);
    printf("%lld",num(a,b));
    return 0;
}


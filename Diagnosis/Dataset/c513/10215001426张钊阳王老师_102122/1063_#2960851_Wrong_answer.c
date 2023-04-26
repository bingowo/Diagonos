#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int plus(long long int x,long long int y);
    long long int x,y;
    long long int sum;

    scanf("%lld %lld",&x,&y);

    sum=plus(x,y);

    printf("%lld",plus(10,1));

    return 0;
}

long long plus(long long int x,long long int y)
{
    long long z=x-y;
    if(x>y)
    {
        if(z>y) return 4*y+plus(z,y);
        if(y>z) return 4*x+plus(y,z);
    }
    if(x==y) return 4*x;
}
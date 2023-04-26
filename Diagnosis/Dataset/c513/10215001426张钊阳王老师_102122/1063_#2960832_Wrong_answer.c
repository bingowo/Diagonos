#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int plus(long long int x,long long int y);
    long long int x,y;
    long long int sum;
    scanf("%lld %lld",&x,&y);
    printf("%lld",plus(x,y));
    return 0;
}

long long int plus(long long int x,long long int y)
{
    long long int sum;
    long long int z=x-y;
    sum=4*y;
    if(x!=y)
    {
        if(z>y) return sum+plus(z,y);
        else if(y>z) return sum+plus(y,z);
    }
    else if(x==y) return sum;
}


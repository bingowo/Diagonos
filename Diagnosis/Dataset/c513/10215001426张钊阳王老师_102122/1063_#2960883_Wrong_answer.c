#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int plus(long long int x,long long int y);
    long long int x,y;
    long long int sum;

    scanf("%lld %lld",&x,&y);
    printf("%lld %lld",x,y);
    
    sum=plus(x,y);

    printf("%lld",sum);

    return 0;
}

long long plus(long long int x,long long int y)
{
    long long z=x-y;
    if(x==y) return 4*y;
    if(x>y)
    {
        if(z>y) {return 4*y+plus(z,y);}
        if(y>z) {return 4*y+plus(y,z);}
    }
}


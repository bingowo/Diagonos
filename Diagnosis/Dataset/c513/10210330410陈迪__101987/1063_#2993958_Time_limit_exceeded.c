#include <stdio.h>

long long farm(long long x, long long y)
{
    if(x==y) return 4*x;
    else if(x>y) {
        long long temp;
        temp = x; x = y; y = temp;
    }
    return 4*x + farm(x,y-x);
}

int main()
{
    long long x,y;
    scanf("%lld %lld",&x,&y);
    printf("%lld",farm(x,y));
    return 0;
}

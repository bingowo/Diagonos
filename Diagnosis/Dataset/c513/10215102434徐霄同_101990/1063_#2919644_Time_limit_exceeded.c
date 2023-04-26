#include <stdio.h>
long long f(long long x,long long y)
{
    if(x==y)
        return x*4;
    else if(x>y)
        return y*4+f(x-y,y);
    else
        return x*4+f(x,y-x);
}
int main()
{
    long long x,y;
    scanf("%lld%lld",&x,&y);
    printf("%lld\n",f(x,y));
    return 0;
}

#include <stdio.h>
#include <string.h>

long long pp(long long x,long long y);
long long len=0;

int main()
{
    long long x,y;//y<=x
    scanf("%lld%lld",&x,&y);
    printf("%lld",pp(x,y));
    return 0;
}

long long pp(long long x,long long y)
{
    if(x==y)
    {
        len+=4*x;
        return len;
    }
    else len+=4*y;
    return y<=(x-y)?pp(x-y,y):pp(y,x-y);
}

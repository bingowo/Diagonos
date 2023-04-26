#include <stdio.h>

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
    long long tmp=x/y;
    len+=4*tmp*y;
    if(x%y==0)return len;
    return pp(y,x%y);
}


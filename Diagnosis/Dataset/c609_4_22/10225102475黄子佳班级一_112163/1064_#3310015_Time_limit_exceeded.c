#include <stdio.h>
#define N 10000

long long pp(long long x,long long y);
long long len=0;
long long memory[N]={0};

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
    if(memory[y]==0)
    {
        memory[y]=4*y;
        len+=memory[y];
    }
    else len+=memory[y];
    return y<=(x-y)?pp(x-y,y):pp(y,x-y);
}


#include<stdio.h>
long long hf(long long x,long long y)
{
    if(x>y)
    {
        return 4*y+hf(x-y,y);
    }
    else if(y>x)
    {
        return 4*x+hf(x,y-x);
    }
    else
    {
        return 4*x;
    }
}
int main()
{
    long long x,y;
    scanf("%lld %lld",&x,&y);
    printf("%lld",hf(x,y));
    return 0;
}
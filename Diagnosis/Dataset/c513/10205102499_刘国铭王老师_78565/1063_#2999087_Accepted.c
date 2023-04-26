#include <stdio.h>

long long solve(long long x,long long y)
{
    if(x<y)
    {
        long long temp=x;
        x=y;
        y=temp;
    }
    if(y==0) return 0;
    long long res=x/y*y*4+solve(x%y,y);
    return res;
}

int main()
{
    long long x,y;
    scanf("%lld%lld",&x,&y);
    printf("%lld", solve(x,y));
    return 0;
}
#include <stdio.h>
long long Plant(long long x,long long y)
{
    if(x < y)
    {
        int m=x;
        x = y;
        y = m;
    }
    if(x == y)
        return 4*x;
    if(x %y==0)
        return (x/y)*y*4;
    return x/y*y*4+ Plant(x%y,y);
}

int main() {
    long long x,y;
    scanf("%lld%lld",&x,&y);
    long long min;
    min = Plant(x,y);
    printf("%lld\n",min);
    return 0;
}

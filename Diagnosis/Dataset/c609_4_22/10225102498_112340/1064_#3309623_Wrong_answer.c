#include <stdio.h>

long long min(long long x, long long y)
{
    return x < y?x:y;
}

int main()
{
    long long x, y, t;
    long long v = 0;
    scanf("%lld%lld", &x, &y);
    while(x&&y)
    {
        t = min(x,y);
        v += 4*t;
        if(x>t)
            x -= t;
        else
            y -= t;
    }
    
    return 0;
}

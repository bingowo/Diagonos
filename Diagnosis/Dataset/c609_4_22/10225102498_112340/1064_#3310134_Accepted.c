#include <stdio.h>

int main()
{
    long long x, y, t;
    long long v = 0;
    scanf("%lld%lld", &x, &y);
    
    while(x!=0 && y!=0)
    {
        if(x>y)
        {
            t = y;
            v += 4 * (x/t) * t;
            x %= t;
        }
        else
        {
            t = x;
            v += 4 * (y/t) * t;
            y %= t;
        }
    }
    printf("%lld\n", v);
    
    return 0;
}

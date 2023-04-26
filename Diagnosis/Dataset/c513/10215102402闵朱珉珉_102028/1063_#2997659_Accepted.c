#include <stdio.h>
#include <string.h>
long long N[75];
long long change (long long x,long long y)
{
    if (x%y==0)
    {
        if (x>y) return x*4;
        else return y*4;
    }
    if (x>y) return 4*y+change(x-y,y);
    if (x<y) return 4*x+change(x,y-x);
}
int main ()
{
    long long x,y;
    scanf ("%lld%lld",&x,&y);
    printf("%lld",change(x,y));
    return 0;
}

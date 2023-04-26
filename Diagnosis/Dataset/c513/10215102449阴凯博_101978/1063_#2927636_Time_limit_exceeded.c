#include <stdio.h>
#include <stdlib.h>


long long stamina(long long x,long long y)
{
    if (x>y)
    {
        return stamina(y,y)+stamina(x-y,y);
    }
    if (x==y)
        return 4*x;
    if (x<y)
    {
        return stamina(x,x)+stamina(x,y-x);
    }

}

int main()
{
    long long x,y;
    scanf("%lld %lld",&x,&y);
    printf("%lld\n",stamina(x,y));
    return 0;
}

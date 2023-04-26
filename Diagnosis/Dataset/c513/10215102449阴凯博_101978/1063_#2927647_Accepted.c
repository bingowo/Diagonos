#include <stdio.h>
#include <stdlib.h>


long long stamina(long long x,long long y)
{

    if (x>y)
    {
        if (x%y==0)
            return (x/y)*stamina(y,y);
        else
            return stamina(y,y)+stamina(x-y,y);
    }
    if (x==y)
        return 4*x;
    if (x<y)
    {
        if (y%x==0)
            return (y/x)*stamina(x,x);
        else
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

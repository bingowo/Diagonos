#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long int p = 0;
void power(long long int x,long long int y)
{
    if(!y)return ;
    else if(x == y)
    {
        p += (4*y);
        return ;
    }
    else
    {
        long long int num = x/y;
        p += (num*4*y);
        power(y,x%y);
    }
}
int main()
{
    long long int x,y;
    scanf("%lld%lld",&x,&y);
    power(x,y);
    printf("%lld\n",p);
    return 0;
}

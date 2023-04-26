#include <stdio.h>
#include <stdlib.h>
long long f(long long x,long long y)
{
    if(y>x)
    {
        long long temp=x;
        x=y;
        y=temp;
    }
    if(x==y)
        return 4*x;
    else
    {
        long long a=4*y;
        long long temp=y;
        y=x-y;
        x=temp;
        return a+f(x,y);
    }

}
int main()
{
    long long x,y;
    scanf("%lld %lld",&x,&y);
    printf("%lld",f(x,y));
    return 0;
}

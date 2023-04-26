#include <stdio.h>
#include <stdlib.h>
unsigned long long f(unsigned long long x,unsigned long long y)
{
    if(y>x)
    {
        unsigned long long temp=x;
        x=y;
        y=temp;
    }
    if(x==y)
        return 4*x;
    else
    {
        unsigned long long a=4*y;
        unsigned long long temp=y;
        y=x-y;
        x=temp;
        return a+f(x,y);
    }

}
int main()
{
    unsigned long long x,y;
    scanf("%llu %llu",&x,&y);
    printf("%llu",f(x,y));
    return 0;
}

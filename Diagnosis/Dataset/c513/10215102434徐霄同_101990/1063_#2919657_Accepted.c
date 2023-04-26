#include <stdio.h>
long long f(long long x,long long y)
{
    long long t;
    if(x<y){
        t=x;
        x=y;
        y=t;
    }
    t=x/y;
    if(x%y==0)
        return 4*y*t;
    else
        return 4*y*t+f(x%y,y);
}
int main()
{
    long long x,y;
    scanf("%lld%lld",&x,&y);
    printf("%lld\n",f(x,y));
    return 0;
}

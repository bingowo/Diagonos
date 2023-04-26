#include <stdio.h>
#include <stdlib.h>
long long f(long long x,long long y)
{
    long long max,min;
    max=x<y?y:x;
    min=x<y?x:y;
    if(min==0)return 0;
    else
    {
        long long num=max/min;
        long long tem=max%min;
        return 4*num*min+f(min,tem);
    }
}
int main()
{
    long long x,y;
    scanf("%lld %lld",&x,&y);
    long long res=f(x,y);
    printf("%lld",res);
    return 0;
}

#include<stdio.h>
long long hf(long long x,long long y)
{
    if(x==0||y==0)return 0;
    else
    {
        long long mul,rem;
        if(x>y)
        {
            mul=x/y;
            rem=x%y;
            return 4*y*mul+hf(rem,y);
        }
        else if(y>x)
        {
            mul=y/x;
            rem=y%x;
            return 4*x*mul+hf(x,rem);
        }
        else
        {
            return 4*x;
        }
    }
}
int main()
{
    long long x,y;
    scanf("%lld %lld",&x,&y);
    printf("%lld",hf(x,y));
    return 0;
}
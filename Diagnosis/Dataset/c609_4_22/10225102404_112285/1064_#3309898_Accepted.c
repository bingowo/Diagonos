#include<stdio.h>

long long f(long long x,long long y)
{
    if(x<y)
    {
        long long temp=x;
        x=y;
        y=temp;
    }
    if(y == 0)
    {
        return 0;
    }
    long long v=x/y*y*4+f(y,x%y);/*x/y为正方形的个数，y为正方形的边长*/
    return v;
}
int main()
{
     long long x,y;
     scanf("%lld %lld",&x,&y);
     printf("%lld\n",f(x,y));
     return 0;
}

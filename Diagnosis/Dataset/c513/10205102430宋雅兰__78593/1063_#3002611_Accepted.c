#include<stdio.h>
long long func(long long x,long long y)
{
    if(!x||!y)return 0;
    if(x>=y)return 4*y*(x/y)+func(y,x%y);
    return 4*x*(y/x)+func(x,y%x);
}
int main()
{
    long long x,y;
    scanf("%lld%lld",&x,&y);
    printf("%lld",func(x,y));
    return 0;
}
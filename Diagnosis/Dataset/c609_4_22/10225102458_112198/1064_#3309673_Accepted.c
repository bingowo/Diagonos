#include <stdio.h>
#include <stdlib.h>

long long change(long long x,long long y)
{
    long long num,r;
    if(x<y){num=x;x=y;y=num;}
    if(y==0)return 0;
    r=x/y;
    x-=r*y;
    return 4*y*r+change(x,y);
}
int main()
{
    long long int x,y;
    scanf("%lld %lld",&x,&y);
    printf("%lld\n",change(x,y));
}

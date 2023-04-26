#include <stdio.h>
#include <stdlib.h>
long long zhongtian(long long x,long long y)
{
    long long i=0,x1=0;
    long long tl;
            i=y/x;
            tl=tl+4*x*i;
            x1=x;
            x=y%x1;y=x1;
        if(x!=0)return zhongtian(x,y);
        else return tl;
}
int main()
{
    long long x=0,y=0,y1=0;
    long long tl=0;
    scanf("%lld %lld",&x,&y);
    if(x>y){y1=x;x=y;y=y1;}
    tl=zhongtian(x,y);
    printf("%lld\n",tl);
    return 0;
}

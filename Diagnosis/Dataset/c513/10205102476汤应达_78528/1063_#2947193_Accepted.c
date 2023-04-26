#include<stdio.h>

long long result(long long x0,long long y,long long res)
{
    if(x0>0 && y>0)
    {
        if(x0>=y) {res+=4*y;result(x0-=y,y,res);}
        else if(y>=x0) {res+=4*x0;result(x0,y-=x0,res);}
        else x0--;
    }
    else return res;
}

int main()
{
    long long x0,y;
    scanf("%lld %lld",&x0,&y);
    if(x0==y || x0%y==0) printf("%lld",4*x0);
    else printf("%lld",result(x0,y,0));
}
#include <stdio.h>
#include <stdlib.h>

long long f(long long x,long long y){
    if(x<y){long long temp=x;x=y;y=temp;}
    if(y==0) return 0;
    long long v=x/y*4*y+f(y,x%y);
    return v;
}

int main()
{
    long long x,y;
    scanf("%lld%lld",&x,&y);
    printf("%lld\n",f(x,y));
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
long long int min(long long int x,long long int y)
{
    if(x<y)return x;
    else return y;
}
long long int max(long long int x,long long int y)
{
    if(x>y)return x;
    else return y;
}
int main()
{
    long long int x,y,v=0,minc,maxc;
    scanf("%lld %lld",&x,&y);
    while(x&&y)
    {
        minc=min(x,y);
        maxc=max(x,y);
        v+=4*minc*(maxc/minc);
        x=minc;
        y=maxc%minc;
    }
    printf("%lld",v);
    return 0;
}

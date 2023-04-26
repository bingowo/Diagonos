#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

long long z=0;

long long ts(long long x,long long y)
{
    long long t;
    if(x==0) return z;
    else if(x<y){t=x;x=y;y=t;}
    else
    {
        z=z+(x/y*y)*4;
        x%=y;return ts(x,y);
    }
}


int main()
{
    long long x,y;
    scanf("%lld %lld",&x,&y);
    long long s(long long x,long long y);
    long long C=ts(x,y);
    printf("%lld",C);

}

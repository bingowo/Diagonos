#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
//#include "myh.h"


int main()
{
    long long z,x,y,t;
    scanf("%lld",&z);
    long long n=(long long)sqrt((double)z);
    while(n*n>z)n--;
    if(n&1)
    {
        if(z<=n*(n+1))
        {
            x=(n-1)/2;
            y=x+1;
            x-=z-n*n;
        }
        else
        {
            x=-(n+1)/2;
            y=-x;
            y-=z-n*(n+1);
        }
    }
    else
    {
        if(z<=n*(n+1))
        {
            x=-n/2;
            y=x;
            x+=z-n*n;
        }
        else
        {
            x=n/2;
            y=-x;
            y+=z-n*(n+1);

        }
    }
    printf("(%lld,%lld)",x,y);
}

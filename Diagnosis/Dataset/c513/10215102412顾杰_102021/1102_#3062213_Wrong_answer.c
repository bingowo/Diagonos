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
    if(n&1)
    {
        if(z<=n*(n+1))
        {
            x=(n-1)/2;
            y=x+1;
            t=n*n;
            while(t!=z)
            {
                t++;
                x--;
            }
        }
        else
        {
            x=-(n+1)/2;
            y=-x;
            t=n*(n+1);
            while(t!=z)
            {
                t++;
                y--;
            }
        }
    }
    else
    {
        if(z<=n*(n+1))
        {
            x=-n/2;
            y=x;
            t=n*n;
            while(t!=z)
            {
                t++;
                x++;
            }
        }
        else
        {
            x=n/2;
            y=-x;
            t=n*(n+1);
            while(t!=z)
            {
                t++;
                y++;
            }
        }
    }
    printf("(%lld,%lld)",x,y);
}

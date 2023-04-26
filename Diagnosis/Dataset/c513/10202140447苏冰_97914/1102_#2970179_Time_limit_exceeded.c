#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int main()
{
    long long n;
    scanf("%lld",&n);
    long long x=0,y=0;
    int flag=1;
    for(int i=1;;i++)
    {
        if(flag)
        {
            if(n>i)
            {
                y+=i;n-=i;
            }
            else
            {
                y+=n;
                break;
            }
            if(n>i)
            {
                x-=i;n-=i;
            }
            else
            {
                x-=n;
                break;
            }
            flag=0;
        }
        else
        {
            if(n>i)
            {
                y-=i;n-=i;
            }
            else
            {
                y-=n;
                break;
            }
            if(n>i)
            {
                x+=i;n-=i;
            }
            else
            {
                x+=n;
                break;
            }
            flag=1;
        }

    }
    printf("(%lld,%lld)",x,y);
    return 0;
}

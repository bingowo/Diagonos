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
    long long i,t;
    for(i=3;;i+=2)
    {
        t=i*i-1;
        if(t>=n) break;
    }
    i-=2;
    long long m=i*i-1;
    x=(i-1)/2;y=(i-1)/2;
    long long cnt=n-m;
    if(cnt>0)
    {
         y++;cnt--;
        while(cnt>0)
        {
            if(cnt>=i)
            {
                x-=i;cnt-=i;break;
            }
            else
            {
                x-=cnt;cnt=0;break;
            }
        }
        while(cnt>0)
        {
            if(cnt>=i+1)
            {
                y-=(i+1);cnt-=(i+1);break;
            }
            else
            {
                y-=cnt;cnt=0;break;
            }
        }
        while(cnt>0)
        {
            if(cnt>=i+1)
            {
                x+=(i+1);cnt-=(i+1);break;
            }
            else
            {
                x+=cnt;cnt=0;break;
            }
        }
        while(cnt>0)
        {
            if(cnt>=i+1)
            {
                y+=(i+1);cnt-=(i+1);break;
            }
            else
            {
                y+=cnt;cnt=0;break;
            }
        }
    }
    printf("(%lld,%lld)",x,y);
    return 0;
}

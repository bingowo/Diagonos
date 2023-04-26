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
    y++;cnt--;
    if(cnt!=0)
    {
        for(int j=0;j<i && cnt!=0;j++)
        {
            x--;cnt--;
        }
        for(int j=0;j<i+1 && cnt!=0;j++)
        {
            y--;cnt--;
        }
        for(int j=0;j<i+1 &&cnt!=0;j++)
        {
            x++;cnt--;
        }
        for(int j=0;j<i+1 && cnt!=0;j++)
        {
            y++;cnt--;
        }
    }
    printf("(%lld,%lld)",x,y);
    return 0;
}

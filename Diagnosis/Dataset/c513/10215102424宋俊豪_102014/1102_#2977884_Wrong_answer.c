#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
    long long x,y,n,t,temp;
    scanf("%lld",&n);
    t=(int)sqrt((double)n);
    if(t%2==0)
    {   temp=t/2;
        x=-t/2;
        y=-t/2;
        if(t*t==n)
        {
            printf("(%lld,%lld)",x,y);
        }
        else
        {
            if(n-t*t<=temp)
                x+=n-t*t;
            else
            {
                x+=temp;
                y+=n-t*t-temp;
            }
             printf("(%lld,%lld)",x,y);
        }
    }
    else
    {   temp=t;
        x=t-2;y=t-1;
        if(t*t==n)
        {
            printf("(%lld,%lld)",x,y);
        }
        else
        {
            if(n-t*t<=temp)
                x-=n-t*t;
            else
            {
                x-=temp;
                y-=n-t*t-temp;
            }
             printf("(%lld,%lld)",x,y);
        }
    }
    return 0;
}

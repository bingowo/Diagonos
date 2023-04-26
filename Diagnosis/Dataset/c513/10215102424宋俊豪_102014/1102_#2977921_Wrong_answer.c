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
    while(t*t<n)
        t++;
    t--;
    if(t==1)
    {
        if(n==1)
            printf("(0,1)");
        else if(n==2)
            printf("(-1,1)");
        else if(n==3)
            printf("(-1,0)");
    }
    else if(t%2==0)
    {   temp=t;
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
        x=t/2;y=t/2+1;
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

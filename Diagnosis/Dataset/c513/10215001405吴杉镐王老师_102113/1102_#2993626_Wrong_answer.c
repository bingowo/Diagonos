#include <stdio.h>

int main()
{
    unsigned long long n;
    scanf("%llud",&n);
    unsigned long long i;
    if(n<=6)
        i=-1;
    else
    {
        for(i=0;4*i*i+10*i+6<n;i++);
        i--;
    }
    unsigned long long sum;
    long long x=0,y=0;
    if(i==-1)
        sum=n;
    else
    {
        sum=n-4*i*i-10*i-6;
        x=i+1;
        y=-i-1;
    }
    //printf("%llu %llu\n",x,y);
    unsigned long long l1=2*x+1,l2=2*x+2;
    //for(;sum;sum--)
    //{
        if(sum<=l1)
            y=y+sum;
        else if(sum<=2*l1)
        {
            y=y+l1;
            x=x-(sum-l1);
        }
        else if(sum<=2*l1+l2)
        {
            x=x-l1;
            y=y+l1-(sum-2*l1);
        }
        else
        {
            y=y+l1-l2;
            x=x-l1+(sum-2*l1+l2);
        }
    //}
    printf("(%lld,%lld)\n",x,y);
}

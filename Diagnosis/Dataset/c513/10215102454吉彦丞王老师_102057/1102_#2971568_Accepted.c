#include<stdio.h>
long long int change(unsigned long long m)
{
    long long int n=1;
    while(n*(n+1)<m)
    {
        n++;
    }
    return n;
}
int main()
{
    unsigned long long a;
    scanf("%llu",&a);
    long long int t=change(a);
    long long int deep=t*(t+1)-a;
    long long int x,y;
    if(deep>=t)
    {
        if(t%2==1)
        {
            x=-(t+1)/2+t;
            y=(t+1)/2-deep+t;
        }
        else
        {
            x=-t/2;
            y=-t/2+deep-t;
        }
    }
    else
    {
        if(t%2==1)
        {
            x=-(t+1)/2+deep;
            y=(t+1)/2;
        }
        else
        {
            x=t/2-deep;
            y=-t/2;
        }
    }
    printf("(%lld,%lld)",x,y);
    return 0;
}
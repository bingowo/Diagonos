#include<stdio.h>
int max(long long int a,long long int b)
{
    if(a>b)
    {
        return 1;
    }
    else if(a==b)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}
int main()
{
    long long int a,b;
    scanf("%lld%lld",&a,&b);
    long long int t=0;
    while(a>0&&b>0)
    {
        if(max(a,b)==1)
        {
            t=t+4*b;
            a=a-b;
        }
        else if(max(a,b)==0)
        {
            t=t+4*b;
            a=0;
            b=0;
        }
        else
        {
            t=t+4*a;
            b=b-a;
        }
    }
    printf("%lld",t);
    return 0;
}
#include <stdio.h>
int ispalindrom(long long n)
{
    long long x=0,y=n;
    while (y>0)
    {
        x=x*10+y%10;
        y/=10;
    }
    if(n == x)
    {
        return 1;
    }
    return -1;
}
long long reversal(long long n)
{
    long long x=0,y=n;
    while (y>0)
    {
        x=x*10+y%10;
        y/=10;
    }
    return x;
}
int main() {
    long long x;
    scanf("%lld",&x);
    int a=1;
    int i=ispalindrom(x);
    if(i)
        printf("0 %lld\n",x);
    else
    {
        long long b= reversal(x);
        while (a<= 1000)
        {
            x+= b;
            if(ispalindrom(x))
            {
                printf("%d %lld\n",a,x);
                break;
            }
            else b= reversal(x);
            a++;
        }
    }
    return 0;
}

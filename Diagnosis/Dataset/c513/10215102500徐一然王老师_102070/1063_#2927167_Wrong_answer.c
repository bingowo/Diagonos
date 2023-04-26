#include <stdio.h>

long long int F(int a, int b)
{
    if(a==1||b==1)
    {
        return 4*a;
    }
    if (a==b)
    {
        return 4*a;
    }
    else if(a>b)
    {
        return F(a-b,b)+F(b,b);
    }
    else
        return F(b-a,a)+F(a,a);
}


int main()
{
    long long int x,y;
    scanf("%lld %lld",&x,&y);
    printf("%lld",F(x,y));
}

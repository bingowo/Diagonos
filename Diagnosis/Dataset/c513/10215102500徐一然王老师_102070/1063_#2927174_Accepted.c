#include <stdio.h>

long long int F(long long int a, long long int b)
{
    if(a==0||b==0)return 0;
    if(b==1)
    {
        return 4*a;
    }
    else if(a==1)
    {
        return 4*b;
    }
    if (a==b)
    {
        return 4*a;
    }
    else if(a>b)
    {
        return F(a-a/b*b,b)+a/b*F(b,b);
    }
    else
        return F(b-b/a*a,a)+b/a*F(a,a);
}


int main()
{
    long long int x,y;
    scanf("%lld %lld",&x,&y);
    printf("%lld",F(x,y));
}

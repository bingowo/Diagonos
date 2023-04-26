#include<stdio.h>
long long int ans = 0;

void fun(long long int x,long long int y)
{
    if(y==0)
    {
        return;
    }
    if(x==y)
    {
        ans = ans+4*x;
        return;
    }
    long long int n = x/y;
    ans = ans+4*n*y;
    x = x-n*y;
    if(x>y)
    {
        fun(x,y);
    }
    else
    {
        fun(y,x);
    }
}

int main()
{
    long long int x,y;
    scanf("%lld %lld",&x,&y);
    if(x<y)
    {
        int temp = y;
        y=x;
        x = temp;
    }
    fun(x,y);
    printf("%lld",ans);
    return 0;
}

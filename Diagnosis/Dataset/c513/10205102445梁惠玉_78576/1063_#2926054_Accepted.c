#include <stdio.h>

void swap(long long x,long long y)
{
    if(y>x)
    {
        long long temp=x;
        x=y;
        y=temp;
    }
    return;
}

long long result(long long x,long long y)
{
    swap(x,y);
    if(y==0)
    {
        return 0;
    }
    else{
        return (y*4)*(x/y)+result(y,x%y);
    }
}

int main()
{
    long long x,y;
    scanf("%lld %lld",&x,&y);
    long long ans=result(x,y);
    printf("%lld\n",ans);
    return 0;
}
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
    if(x==0&&y==0)
    {
        return 1;
    }
    else{
        long long temp=y*4;
        if(y*y!=x*y)
        {
            x-=y;
            swap(x,y);
        }
        else
        {
            y-=y;
            x-=y;
        }
        return temp*result(x,y);
        
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
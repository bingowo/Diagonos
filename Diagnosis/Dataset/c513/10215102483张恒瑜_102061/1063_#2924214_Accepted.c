#include<stdio.h>

long long max(long long x, long long y)
{
    return x>y? x:y;
}

long long min(long long x, long long y)
{
    return x<y? x:y;
}

int main()
{
    long long x,y,res=0;
    scanf("%lld %lld",&x,&y);
    while (x!=0 && y!=0)
    {
        long long cnt=max(x,y)/min(x,y);
        res+=4*min(x,y)*cnt;
        if(x>y) x-=y*cnt;
        else y-=x*cnt;
    }
    printf("%lld",res);
}
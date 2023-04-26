#include<stdio.h>//辗转相除法的应用

long long f(long long x,long long y)
{
    long long min = (x > y) ? y : x;
    long long max = (x < y) ? y : x;
    long long end = 0;
    while(max % min)
    {
        long long num = max / min;
        end += min * 4 * num;
        long long t = min;
        min = max % min;
        max = t;
    }
    end += max * 4;
    return end;
}
int main()
{
    long long x,y;
    scanf("%lld %lld",&x,&y);
    printf("%lld",f(x,y));
    return 0;
}


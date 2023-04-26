#include<stdio.h>
long f(long x,long y)
{
    long min = (x > y) ? y : x;
    long max = (x > y) ? x : y;
    long end = 0;
    while (max % min)
    {
        long num = max / min;
        end += min * 4 * num;
        long t = min;
        min = max % min;
        max = t;
    }
    return end + max * 4;
}
int main()
{
    long x, y;
    scanf("%ld %ld", &x, &y);
    printf("%ld", f(x, y));
    return 0;
}
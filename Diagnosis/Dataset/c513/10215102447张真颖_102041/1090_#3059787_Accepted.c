#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long long n,re;
    double x,y;
    while(scanf("%ld",&n)!=EOF&&n)
    {
        x=n*log10(n);
        y=(long long)x;
        x=x-y;
        re=(long long)pow(10.0,x);
        printf("%d\n",re);
    }
    return 0;
}
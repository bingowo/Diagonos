#include<stdio.h>

void swap(long long int *a, long long int *b);
int main()
{
    long long int x,y;
    long long res=0;
    long long times;
    scanf("%lld %lld",&x,&y);
    
    while (x!=y)
    {
        if (x<y) swap(&x,&y);
        times=x/y;
        res+=times*(4*y);
        x-=times*y;
        if (!x) break;
    }
    res+=4*x;
    printf("%lld",res);
    return 0;
}

void swap(long long int *a, long long int *b)
{
    long long t=*a;
    *a=*b;
    *b=t;
    return;
}
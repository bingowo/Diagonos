#include<stdio.h>

void swap(long long int *a, long long int *b);
int main()
{
    long long int x,y;
    long long res=0;
    long long times;
    int i;
    scanf("%lld %lld",&x,&y);
    
    while (x!=y)
    {
        times=0;
        if (x<y) swap(&x,&y);
        while (times*y<x)
        {
            times++;
        }
        times--;
        res+=times*(4*y);
        x-=times*y;
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

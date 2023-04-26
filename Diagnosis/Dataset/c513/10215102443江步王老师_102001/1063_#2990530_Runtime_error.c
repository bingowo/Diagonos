#include<stdio.h>

long long count(long long bigger, long long smaller);
void swap(long long *a, long long *b);
int main()
{
    long long x,y;
    scanf("%lld %lld",&x,&y);
    long long res=count(x,y);
    printf("%lld",res);
    return 0;
}

long long count(long long bigger, long long smaller)
{
    if (bigger==smaller)
    {
        return 4*bigger;
    }
    else
    {
        if (smaller>bigger)
        {
            swap(&bigger,&smaller);
        }
        long long times=bigger/smaller;
        return (times*count(smaller,smaller)+count(bigger-times*smaller,smaller));
    }
} 

void swap(long long *a, long long *b)
{
    long long t=*a;
    *a=*b;
    *b=t;
    return;
}
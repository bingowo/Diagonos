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
        return ((bigger/smaller)*count(smaller,smaller)+count(bigger-(bigger/smaller)*smaller,smaller));
    }
} 

void swap(long long *a, long long *b)
{
    long long t=*a;
    *a=*b;
    *b=t;
    return;
}
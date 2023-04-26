#include<stdio.h>

long long count(long long int bigger, long long int smaller);
void swap(long long int *a, long long int *b);
int main()
{
    long long int x,y;
    scanf("%lld %lld",&x,&y);
    printf("%lld",count(x,y));
    return 0;
}

long long count(long long int bigger, long long int smaller)
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
        return (count(smaller,smaller)+count(bigger-smaller,smaller));
    }
} 

void swap(long long int *a, long long int *b)
{
    long long t=*a;
    *a=*b;
    *b=t;
    return;
}
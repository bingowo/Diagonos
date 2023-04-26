#include <stdlib.h>
#include <stdio.h>

void Max(long long int*a,long long int*b)
{
    long long int temp;
    if(*a < *b)
    {
        temp = *a;
        *a = *b;
        *b = temp;
    }
}

int main()
{
    long long int x,y;
    unsigned long long int s = 0;
    scanf("%lld %lld",&x,&y);
    Max(&x,&y);
    while(y != 0)
    {
        s += y*4;
        x -= y;
        Max(&x,&y);
    }
    printf("%llu",s);
}
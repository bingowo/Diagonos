#include<stdio.h>
#include<stdlib.h>

long long square(long long x, long long y){
    if(x == y) return 4*x;
    else{
        if(x < y){
            long long temp = x;
            x = y;
            y = temp;
        }
        if(x % y == 0){
            return (x/y)*y*4;
        }
        else
            return 4*y + square(x-y,y);
    }
}

int main(void)
{
    long long x,y;
    scanf("%lld%lld",&x,&y);

    printf("%lld",square(x,y));
    return 0;
}
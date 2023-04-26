#include <stdio.h>
#include <stdlib.h>

long long int f(long long int x,long long int y)
{
    long long int temp;
    if(x < y)
    {
        temp = x;
        x = y;
        y = temp;
    }
    if(y == 0)
        return 0;
    else
        return f(x - y,y) + y*4; 

}

int main()
{
    long long int x,y;
    scanf("%lld %lld",&x,&y);
    printf("%lld",f(x,y));
    return 0;
}
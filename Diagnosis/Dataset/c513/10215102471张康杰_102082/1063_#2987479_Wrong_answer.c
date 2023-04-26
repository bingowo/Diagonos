#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int f(long long int x,long long int y,long long int*ar)
{
    long long int temp,s;
    if(x < y)
    {
        temp = x;
        x = y;
        y = temp;
    }
    if(ar[y] != -1)
        return ar[y];
    if(y == 0)
        s = 0;
    else
        s =  f(x - y,y,ar) + y*4;
    ar[y] = s;
    return s; 
}

int main()
{
    long long int x,y;
    long long int*ar;
    ar = (long long int*)malloc(sizeof(long long int)*x);
    memset(ar,-1,sizeof(long long int)*x);
    scanf("%lld %lld",&x,&y);
    printf("%lld",f(x,y,ar));
    free(ar);
    return 0;
}
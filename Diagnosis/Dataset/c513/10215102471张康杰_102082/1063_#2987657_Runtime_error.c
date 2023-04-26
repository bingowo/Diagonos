#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int f(long long int x,long long int y,long long int*ar)
{
    long long int temp,s = 0;
    if(x < y)
    {
        temp = x;
        x = y;
        y = temp;
    }
    if(ar[y] == -1)
        ar[y] = 4*y;
    if(y == 0)
        s = 0;
    else
    {
        if(ar[y] != -1)
            s =  f(x - y,y,ar) + ar[y];
        else
        {
            ar[y] = 4*y;
            s =  f(x - y,y,ar) + ar[y];
        }
    }
    return s;
}

int main()
{
    long long int x,y,len,s1,re;
    long long int*ar;
    scanf("%lld %lld",&x,&y); 
    if(x > y)
    {
        re = x / y;
        s1 = 4 * y * re;
        x = x - re * y;
    }
    else
    {
        re = y / x;
        s1 = 4 * x * re;
        y = x - re * x;
    }
    len = (x>y)?y:x;
    ar = (long long int*)malloc(sizeof(long long int)*(len + 1));
    memset(ar,-1,sizeof(long long int)*(len + 1));
    printf("%lld",f(x,y,ar) + s1);
    free(ar);
    return 0;
}
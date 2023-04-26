#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int f(int n)
{
    if(n < 3)
        return 0;
    else
        return f(n - 1) + pow(2,n - 3) - f(n - 3); 
}

int main()
{
    int n;
    while(scanf("%d",&n))
    {
        if(n == -1)
            break;
        printf("%d\n",pow(2,n) - f(n));    
    }
    return 0;
}   
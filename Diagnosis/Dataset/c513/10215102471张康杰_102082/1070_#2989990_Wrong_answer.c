#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int f(int n)
{
    if(n == 1)
        return 2;
    else if(n == 2)
        return 4;
    else if(n <= 0)
        return 0;
    else
        return f(n - 1) + f(n - 3) * 3; 
}

int main()
{
    int n;
    while(scanf("%d",&n))
    {
        if(n == -1)
            break;
        printf("%d\n",f(n));    
    }
    return 0;
}   
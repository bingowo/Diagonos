#include <stdio.h>
#include <stdlib.h>

int f(int n)
{
    if(n == 0 || n == 1)
        return 1;
    else if(n < 0)
        return 0;
    else
        return f(n - 1) + f(n - 2) + f(n - 3) + f(n - 4);
}

int main()
{
    int T,i,n;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        scanf("%d",&n);
        printf("case #%d:\n%d",f(n));
    }    
}
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int f(int n,int m)
{
    if(n == m)
        return 1;
    else if(n < m)
        return 0;
    else
        return f(n - 1,m) + pow(2,n - m - 1) - f(m,n - m - 1);
}

int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m))
    {
        if(n == -1)
            break;
        printf("%d\n",f(n,m));
    }
    return 0;
}
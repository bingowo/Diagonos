#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int f(int n)
{
    if(n==0) return 0;
    if(n==1) return 2;
    if(n==2) return 4;
    if(n==3) return 7;
    if(n>3)
    {
        return (2*f(n-1)-f(n-2)+f(n-3));
    }
}
int main()
{
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(n==-1) break;
        printf("%d\n",f(n));
    }
    return 0;
}


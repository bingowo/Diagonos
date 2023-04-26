#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int result(int n)
{
    if(n==1)
        return 2;
    if(n==2)
        return 4;
    if(n==3)
        return 7;
    return 2* result(n-1)- result(n-2)+ result(n-3);
}

int main()
{
    int n;
    scanf("%d",&n);
    while (n!=-1)
    {
        int r=result(n);
        printf("%d\n",r);
        scanf("%d",&n);
    }
    return 0;
}
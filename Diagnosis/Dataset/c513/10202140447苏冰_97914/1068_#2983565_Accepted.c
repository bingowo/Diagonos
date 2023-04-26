#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int f(int n,int m)
{
    if(n<m) return 0;
    if(n==m) return 1;
    return 2*f(n-1,m)-f(n-m-1,m)+pow(2,n-1-m);
}
int main()
{
    int n,m;
    while(1)
    {
        scanf("%d %d",&n,&m);
        if(n==-1 && m==-1) break;
        printf("%d\n",f(n,m));
    }
    return 0;
}

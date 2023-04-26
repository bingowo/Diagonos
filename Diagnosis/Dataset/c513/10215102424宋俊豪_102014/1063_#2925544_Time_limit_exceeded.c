#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
int max(int x,int y)
{
    if(x>y)
        return x;
    else
        return y;
}
int min(int x,int y)
{
    if(x>y)
        return y;
    else
        return x;
}
int slo(int n,int m)
{   int s;
    if(n==m)
        return n*4;
    else
    {
        s=4*min(n,m);
        return s+slo(abs(n-m),min(n,m));
    }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    printf("%d",slo(n,m));
    return 0;
}

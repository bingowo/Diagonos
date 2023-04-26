#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int a;int t=0;
int g(int n)
{
    if(n==1) return a;
    if(n==2) return t;
    return g(n-2)+g(n-1);
}
int f(int n)
{
    if(n==1) return a;
    if(n==2) return a;
    return f(n-1)+g(n-2);
}
int main()
{
     int n,m,x;
     scanf("%d %d %d %d",&a,&n,&m,&x);
     while(f(n-1)!=m) t++;
     printf("%d",f(x));
     return 0;
}

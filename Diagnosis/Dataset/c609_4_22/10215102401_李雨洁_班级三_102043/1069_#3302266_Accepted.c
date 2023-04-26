#include <stdio.h>
#include <math.h>
int f(int n,int m)
{
    if(n<m) return 0;
    if(n==m) return 1;
    else
        return 2*f(n-1,m)-f(n-1-m,m)+pow(2,n-1-m);
}
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m))
    {
        if(n==-1 && m==-1)break;
        else
            printf("%d\n",f(n,m));
    }
    return 0;
}

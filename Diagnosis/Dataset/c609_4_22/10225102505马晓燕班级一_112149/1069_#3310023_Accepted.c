#include <stdio.h>
#include <stdlib.h>

int f(int n,int m,int p[])
{
    if(n<m)
        return p[n]=0;
    else if(n==m)
        return p[n]=1;
    else if(p[n]>0)
        return p[n];
    else
        p[n]=2 * f(n-1,m,p) - f(n-1-m,m,p) + (1 << (n-m-1)); //2^(n-m-1)
    return p[n];
}

int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m),n!=-1 || m !=-1)
    {
        int p[32]={0};
        printf("%d\n",f(n,m,p));

    }
    return 0;
}
#include<stdio.h>
int f(int n,int m)
{
    if(n<m)
    {
        return 0;
    }
    else if(n==m)
    {
        return 1;
    }
    else
    {
        return 2*f(n-1,m)-f(n-m-1,m)+(1<<(n-m-1));
    }
}
int main()
{
    int n=0,m=0,k=0;
    while(k==0)
    {
        scanf("%d %d",&n,&m);
        if(n==-1&&m==-1)
        {
            break;
        }
        printf("%d\n",f(n,m));
    }
    return 0;
}
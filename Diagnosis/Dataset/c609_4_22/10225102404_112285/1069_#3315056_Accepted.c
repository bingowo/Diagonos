#include<stdio.h>

int count(int n,int m)
{
    if(n < m)
    {
        return 0;
    }
    if(n == m)
    {
        return 1;
    }
    return 2*count(n-1,m)-count(n-m-1,m)+(1 << (n-m-1));
}
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)&&m != -1)
    {
        printf("%d\n",count(n,m));
    }
    return 0;
}

#include<stdio.h>

int count(int n,int m)/*正向思考*/
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
int dp(int n,int m)/*反向思考*/
{
    if(n==0)
    {
        return 1;
    }
    if(n < m)
    {
        return 1<<n;
    }
    if(n == m)
    {
        return (1<<n)-1;/*只有n个一这一种情况不含连续m个1字串*/
    }
    return 2*dp(n-1,m)-dp(n-1-m,m);
}
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)&&m != -1)
    {
        printf("%d\n",(1<<n)-dp(n,m));
    }

    return 0;
}

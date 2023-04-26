#include<stdio.h>
int main()
{
    int a,n,m,x;
    scanf("%d %d %d %d",&a,&n,&m,&x)
    int dp[30];
    dp[1]=a;
    dp[2]=a;
    int up[30],down[30];
    if (x==n)
    {
        printf("%d",m);
        return 0;
    }
    up[1]=a;
    up[2]=a;
    down[1]=a;
    down[2]=a;
    for(int i=3;i<=x;i++)
    {
        up[i]=up[i-1]+up[i-2];
        down[i]=up[i-1];
        dp[i]=dp[i-1]-down[i]+up[i];
    }
    printf("%d",dp[x]);
}
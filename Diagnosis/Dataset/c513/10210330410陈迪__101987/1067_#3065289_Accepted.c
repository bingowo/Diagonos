#include<stdio.h>
long long dp[75];
long long IT(int num)
{
    if(num == 0)
    {
        return 0;
    }
    if(num == 1 || num == 2)
    {
        return 1;
    }
    if(dp[num]) //计算过的项直接返回
    {
        return dp[num];
    }
    dp[num] = IT(num - 1) + IT(num - 2) + IT(num - 3);
    return dp[num];
}
int main()
{
    int t,n;
    scanf("%d",&t);
    for(int i = 0; i < t; i++)
    {
        scanf("%d",&n);

        printf("case #%d:\n", i);
        printf("%lld\n",IT(n));
    }
    return 0;
}

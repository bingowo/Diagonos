#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MOD (long long)(1e9 + 7)

long long  dp[300][210];
int arr[1000];

int main()
{
    int t;
    scanf("%d",&t);
    for(int i = 0; i < t; i++)
    {
        char s[120];
        scanf("%s",s);
        memset(dp,0,sizeof(dp));
        memset(arr,0,sizeof(arr));
        dp[0][0] = 1;//默认不加数字是0，唯一的状态
        int len = strlen(s);
        for(int i = 0; i < len; i++)
        {
            arr[i] = s[i] - '0';
        }

        for(int i = 0; i < len; i++)
        {
            for(int rem = 0; rem < 210; rem++)
            {
                long long temp = 0;
                for(int j = i + 1; j <= len; j++)
                {
                    temp *= 10;
                    temp += arr[j - 1];
                    temp %= 210;

                    dp[j][(rem + temp) % 210] += dp[i][rem];
                    dp[j][(rem + temp) % 210] %= MOD;

                    dp[j][(rem - temp + 210) % 210] += dp[i][rem];
                    dp[j][(rem - temp + 210) % 210] %= MOD;
                }
            }
        }

        long long ans = 0;
        for(int i = 0; i < 210; i++)
            if(!(i % 2) || !(i % 3) || !(i % 5) || !(i % 7))
            {
                ans += dp[len][i];
                ans %= MOD;
            }

        printf("%lld\n",ans * ((MOD + 1) / 2) % MOD );
        //在mod里面除以2，找逆元
        //当然，在上面三重循环的过程中处理一下i=0，j=1没有-的情况也可以不进行逆元操作
    }

    return 0;
}

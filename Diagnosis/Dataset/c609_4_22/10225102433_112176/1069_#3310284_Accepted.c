#include <stdio.h>
#include <math.h>
#include <string.h>



int main()
{
    long long int dp[35];
    int a,b;
    while(scanf("%d %d",&a,&b) && (a != -1 || b != -1))
    {
        memset(dp,0,sizeof(dp));
        dp[b] = 1;
        for(int i = b+1;i <= a;i++)
        {
            dp[i] = 2*dp[i-1];
            if(i == b+1) dp[i]++;
            else
            {
                dp[i] += pow(2,i-b-1)-dp[i-b-1];
            }
        }

        printf("%lld\n",dp[a]);
    }
    return 0;
}
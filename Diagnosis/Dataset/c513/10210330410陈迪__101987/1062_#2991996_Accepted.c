#include <stdio.h>

long long dp[51]={0,1,2,4,8};

long long stairs(int num)
{
    if(num==1) return dp[1];
    else if(num==2) return dp[2];
    else if(num==3) return dp[3];
    else if(num==4) return dp[4];
    else {
        long long t_1 = dp[num-1]? dp[num-1]:stairs(num-1);
        long long t_2 = dp[num-2]? dp[num-2]:stairs(num-2);
        long long t_3 = dp[num-3]? dp[num-3]:stairs(num-3);
        long long t_4 = dp[num-4]? dp[num-4]:stairs(num-4);
        dp[num] = t_1 + t_2 + t_3 + t_4;
        return dp[num];
    }
}

int main()
{
    int N; scanf("%d",&N);
    for(int j=0;j<N;j++)
    {
        printf("case #%d:\n",j);
        int n; scanf("%d",&n);
        printf("%lld\n",stairs(n));
    }
    return 0;
}

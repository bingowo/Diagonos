#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    int a[4]={4,3,2,1};
    for(int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        long long int dp[n+1];
        dp[0]=1;
        for(int j=0;j<4;j++)
        {
            for(int k=a[j];k<n+1;k++)
                dp[k]+=dp[k-a[j]];
        }
        printf("%lld\n",dp[n]);
    }
}

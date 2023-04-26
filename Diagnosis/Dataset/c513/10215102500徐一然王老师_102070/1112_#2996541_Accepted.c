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
        for(int k=1;k<=n;k++)
        {
            if(k%a[0]==0) dp[k]=1;
            else
            {
                dp[k]=0;
            }
        }
        for(int j=1;j<4;j++)
        {
            for(int q=1;q<=n;q++)
                if(q>=a[j])dp[q]=dp[q]+dp[q-a[j]];
        }
        printf("%lld\n",dp[n]);
    }
}

#include <stdio.h>
#include <stdlib.h>




int main()
{
    int n,m;
    while (1)
    {
        scanf("%d %d",&n,&m);
        int dp[35]={0};
        if (m==-1 && n==-1) break;
        for (int i=1;i<m;i++)
            dp[i]=1<<i;
        dp[m]=(1<<m)-1;
        for (int i=m+1;i<=n;i++)
            for (int j=1;j<=m;j++)
                dp[i]+=dp[i-j];
        int a=1<<n;
        printf("%d\n",a-dp[n]);

    }
    return 0;
}

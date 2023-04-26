#include<stdio.h>
int main()
{
    int w;
    scanf("%d",&w);
    int a,b,k,n,m;
    for(int i=0;i<w;i++)
    {
        int dp[1100][1100];
        scanf("%d %d %d %d %d",&a,&b,&k,&n,&m);
        int p,q;
        dp[1][0]=a%10007;
        dp[0][1]=b%10007;
        for(p=2;p<=k;p++) dp[p][0]=(a*dp[p-1][0])%10007;
        for(q=2;q<=k;q++) dp[0][q]=(b*dp[0][q-1])%10007;
        for(p=1;p<=k;p++) for(q=1;q<=k;q++) dp[p][q]=(a*dp[p-1][q]+b*dp[p][q-1])%10007;
        printf("case #%d:\n%d\n",i,dp[n][m]);
    }
}

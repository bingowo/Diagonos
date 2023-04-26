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
        for(p=0;p<=k;p++) 
        {
            dp[p][1]=(a*k)%10007;
            dp[p][0]=0;
        }
        for(q=0;q<=k;q++) 
        {
            dp[1][q]=(b*k)%10007;
            dp[0][q]=0;
        }
        for(p=2;p<=k;p++) 
        {
            for(q=2;q<=k;q++) dp[p][q]=(a*dp[p-1][q]+b*dp[p][q-1])%10007;
        }
        printf("case #%d:\n%d\n",i,dp[n][m]);
    }
}
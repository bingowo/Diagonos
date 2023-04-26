#include <stdio.h>
#include <stdlib.h>

int f(int n,int m,int a,int b)
{
    static int dp[1000][1000]={1};
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i+j){
                if(i==0) dp[i][j]=b*dp[i][j-1]%10007;
                else if(j==0) dp[i][j]=a*dp[i-1][j]%10007;
                else dp[i][j]=(a*dp[i-1][j]+b*dp[i][j-1])%10007;
            }
        }
    }
    return dp[n][m];
}

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int a=0,b=0,k=0,n=0,m=0;
        scanf("%d %d %d %d %d",&a,&b,&k,&n,&m);
        int ans=f(n,m,a,b);
        printf("case #%d:\n",t);
        printf("%d\n",ans);
    }
    return 0;
}

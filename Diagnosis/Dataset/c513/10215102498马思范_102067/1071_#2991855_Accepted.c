#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
long long find(long long n,long long m,long long a,long long b){
    long long dp[1001][1001]={1};
    int x,y;
    for(x=0;x<=n;x++)
    {
        for(y=0;y<=m;y++)
        {
            if(x+y)
            {
                if(x==0)
                {
                    dp[x][y]=dp[x][y-1]*b%10007;
                }
                else if(y==0){
                    dp[x][y]=dp[x-1][y]*a%10007;
                }
                else
                {
                    dp[x][y]=(a*dp[x-1][y]+b*dp[x][y-1])%10007;
                }
            }
        }
    }
    return dp[n][m];
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int I=0;I<T;I++)
    {
        long long a,b,k,n,m;
        scanf("%lld%lld%lld%lld%lld",&a,&b,&k,&n,&m);
        printf("case #%d:\n",I);
        printf("%llu\n",find(n,m,a,b));
    }
    return 0;
}
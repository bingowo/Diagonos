#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)&&n!=-1&&m!=-1){
        int dp[32]={0};
        for(int i=0;i<m;i++)dp[i]=pow(2,i);
        dp[m]=pow(2,m)-1;
        for(int i=m+1;i<=n;i++){
            for(int j=i-1;j>=i-m;j--)dp[i]+=dp[j];
        }
        int ans=pow(2,n)-dp[n];
        printf("%d\n",ans);
    }
    return 0;
}

#include<stdio.h>
int main(){
    long long int dp[51];
    dp[0]=1;dp[1]=1;dp[2]=2;dp[3]=4;dp[4]=8;
    for(int i=5;i<=50;i++){
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3]+dp[i-4];
    }
    int t;scanf("%d",&t);getchar();
    int cas=0;
    while (t--)
    {
        int n;
        scanf("%d",&n);getchar();
        printf("case #%d:\n%lld\n",cas++,dp[n]);   
    }
}
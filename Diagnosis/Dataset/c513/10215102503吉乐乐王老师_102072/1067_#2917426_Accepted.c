#include<stdio.h>
int main(){
    unsigned long long int dp[74];
    dp[0]=0;dp[1]=dp[2]=1;
    for(int i=3;i<74;i++)
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    int t;int cas=0;
    scanf("%d",&t);getchar();
    while(t--){
        int n;
        scanf("%d",&n);getchar();
        printf("case #%d:\n%llu\n",cas++,dp[n]);
    }
}
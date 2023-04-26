#include<stdio.h>
int main(){
    int t,x1,x2,x3,x4,dp[1111]={0},type[4]={4,3,2,1};
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=0;i<4;i++){
        for(int j=type[i];j<=1000;j++){
            dp[j]+=dp[j-type[i]];
        }
    }
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n;
        scanf("%d",&n);
        printf("%d\n",dp[n]);
    }
    return 0;
}
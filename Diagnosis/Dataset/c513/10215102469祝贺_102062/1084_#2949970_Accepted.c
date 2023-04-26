#include<stdio.h>
long long dp[35];
long long find(int n){
    if(dp[n]==0){
        long long a=2,ret=1;
        while(n!=0){
            if(n%2==1){
                ret*=a;
            }
            if(n>1){
                a*=a;
            }
            n/=2;
        }
        dp[n]=ret;
        return ret;
    }
    else return dp[n];
}
int main(){
    int pro;scanf("%d",&pro);
    for(int index=0;index<pro;index++){
            int n;scanf("%d",&n);
        long long ans=find(n);
        printf("case #%d:\n%d\n",index,ans);
    }
    return 0;
}

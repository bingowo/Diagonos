#include<stdio.h>
#include<stdlib.h>
#define N 74
long long T_fib(int n){
    long long dp[N]={0};
    dp[1]=dp[2]=1;
    for(int i=3;i<N;++i)dp[i]=dp[i-3]+dp[i-2]+dp[i-1];
    return dp[n];
}
int main(){
    int T,a=0;
    scanf("%d\n",&T);
    while(a<T){
        int n;
        scanf("%d\n",&n);
        long long ret=T_fib(n);
        printf("case #%d:\n",a);
        printf("%lld\n",ret);
        a++;
    }
    return 0;
}
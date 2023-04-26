#include <stdio.h>
int main(){
    int pri[168] = {2, 3}; int cnt = 2;
    for(int i = 5; i<1000; i++){
        int ip = 1;
        for(int j = 2; j < i/2+1; j++){
            if(i%j==0){ip = 0; break;}
        }
        if(ip){ pri[cnt++] = i; }
    }
    int n; scanf("%d", &n);
    if(n==1){
        printf("0"); return 0;
    }
    long long dp[1001] =  {1};
    for(int i = 0; i<cnt && pri[i] <= n; i++){
        for(int j = pri[i]; j<=n; j++){
            dp[j] += dp[j-pri[i]];
        }
    }
    printf("%lld ", dp[ n ] );
    return 0;
}
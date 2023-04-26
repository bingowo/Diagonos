#include<stdio.h>
#include<string.h>
#define ll long long

ll sup[20] = {0};
ll dp[20][200] = {0};

ll dfs(ll pos, ll miao, ll limit){
    if (pos<=0) {
        if (miao%9==0) return 0;
        else return 1;
    }
    if (!limit && dp[pos][miao]!=0) return dp[pos][miao];
    ll res = 0, max_num=limit?sup[pos]:8;
    for (ll i=0; i<=max_num; i++){
        if (i==9) continue;
        res += dfs(pos-1, miao+i, limit&&(i==max_num));
    }
    if (!limit) dp[pos][miao] = res;
    return res;
}

ll part(ll x){
    ll index = 0;
    memset(dp, 0, sizeof(int)*20*200);
    while(x){
        sup[++index] = x%10;
        x/=10;        
    }
    return dfs(index, 0, 1);
}
int main(){
    ll a, b;
    scanf("%lld %lld", &a, &b);
    printf("%lld\n", part(b)-part(a-1));
    return 0;
}

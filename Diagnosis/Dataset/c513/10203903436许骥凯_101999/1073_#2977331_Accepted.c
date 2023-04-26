#include<stdio.h>
#include<string.h>
#define ll long long 
ll dp[20][10];
int a[20];

ll dfs(int pos, int sta, int limit){
    if (pos == -1 ) return sta != 0;
    if (!limit && dp[pos][sta] != -1) return dp[pos][sta];
    int up = limit? a[pos]: 9;
    ll tmp = 0;
    for (int i = 0; i <= up; i++){
        if (i == 9) continue;
        tmp += dfs(pos-1, (sta * 10 + i) % 9, limit && i == a[pos]);
    }
    if (!limit) dp[pos][sta] = tmp;
    return tmp;
}


ll solve(ll t){
    int pos = 0;
    do{
        a[pos++] = t % 10;
        t /= 10;
    }while(t);
    return dfs(pos - 1, 0, 1);
}

int main(){
    memset(dp, -1, sizeof(dp));
    ll a, b; scanf("%lld%lld", &a, &b);
    printf("%lld\n", solve(b) - solve(a - 1));
    return 0;
}
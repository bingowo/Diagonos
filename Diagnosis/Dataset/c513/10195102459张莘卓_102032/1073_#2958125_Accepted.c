#include <stdio.h>
#include <memory.h>
int a[20];
long long dp[20][9];

long long dfs(int pos, int state, int sum, int limit) {
    if(pos == -1) return 1;
    if(! limit && dp[pos][state] != -1)
        return dp[pos][state];
    int sup = limit ? a[pos] : 9;
    long long ans = 0;
    for(int i=0; i<=sup; ++i) {
        if(i == 9) continue;
        if(pos==0 && (i+sum)%9 == 0) continue;
        ans += dfs(pos-1, (i+sum) % 9, i+sum, limit && i==a[pos]);
    }
    if(! limit) dp[pos][state] = ans;
    return ans;
}

long long solve(long long n) {
    int pos = 0;
    do{
        a[pos++] = n % 10;
        n /= 10;
    }while(n);
    return dfs(pos-1, 0, 0, 1);
}

int main()
{
    long long a, b;
    scanf("%lld %lld",&a, &b);
    memset(dp, -1, sizeof(dp));
    printf("%lld\n",solve(b)-solve(a-1));
    return 0;
}

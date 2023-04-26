#include <stdio.h>
#include <memory.h>

int num[20];
long long dp[20][9];

long long dfs(int pos, int limit, int state){
    if(!limit && dp[pos][state]!=-1)
        return dp[pos][state];
    long long ans = 0;
    int sup = limit ? num[pos] : 9;
    for(int i=0; i<=sup; ++i) {
        if(i == 9) continue;
        if(pos == 0) ans += (state+i) % 9 != 0;
        else ans += dfs(pos-1, limit && i==sup, (state+i)%9);
    }
    if(!limit) dp[pos][state] = ans;
    return ans;
}

long long solve(long long n) {
    int pos = 0;
    memset(dp, -1, sizeof(dp));
    do{
        num[pos++] = n % 10;
        n /= 10;
    }while(n);
    return dfs(pos-1, 1, 0);
}

int main()
{
    long long a, b;
    scanf("%lld %lld",&a, &b);
    printf("%lld\n",solve(b)-solve(a-1));
    return 0;
}

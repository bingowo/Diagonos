#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define ll long long
#define ull unsigned long long
using namespace std;

const ull N = 10010;

int main()
{
    ull n, cnt = 0;
    cin >> n;
    vector<ull> dp(N), primes(N);
    vector<bool> vis(N);
    dp[0] = 1, vis[1] = true;
    for (ull i = 2; i <= n; ++i)
    {
        if (!vis[i])
            primes[++cnt] = i;
        for (ull j = 1; j <= cnt && primes[j] * i <= n; ++j)
        {
            vis[i * primes[j]] = true;
            if (!(i % primes[j]))
                break;
        }
    }
    for (ull i = 2; i <= n; i++)
        if (!vis[i])
            for (ull j = i; j <= n; j++)
                dp[j] += dp[j - i];
    cout << dp[n] << endl;
    return 0;
}
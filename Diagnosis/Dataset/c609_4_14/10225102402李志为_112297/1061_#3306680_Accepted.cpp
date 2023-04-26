#include <iostream>
#include <string>
#include <vector>
#include <cmath>
constexpr int MAXN = 1000;
using namespace std;

bool isPrime(int n)
{
    if (n == 2) return true;
    for (int i = 2; i <= sqrt(n) + 1; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void prime(vector<int>& primes)
{
    for (int i = 2; i <= MAXN; i++) {
        if (isPrime(i)) primes.push_back(i);
    }
}

void DP(vector<int64_t>& dp, const vector<int>& primes)
{
    for (int i = 0; i < primes.size(); i++) {
        for (int j = primes[i]; j <= MAXN; j++) {
            dp[j] += dp[j - primes[i]];
        }
    }
}

int main()
{
    vector<int> primes;
    prime(primes);
    vector<int64_t> dp(MAXN + 1, 0);
    dp[0] = 1;
    DP(dp, primes);
    int in{ 0 };
    cin >> in;
    cout << dp[in] << endl;
    return 0;
}
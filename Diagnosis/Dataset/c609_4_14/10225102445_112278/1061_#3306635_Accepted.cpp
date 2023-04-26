#include <iostream>
#include <vector>
using namespace std;
const int N = 1010;
int n;
long long dp[N];
bool is_prime[N];
vector<int> primes;

void get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!is_prime[i]) primes.push_back(i);
        for (int j = 0; primes[j] <= n / i; j++) {
            is_prime[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

int main() {
    cin >> n;
    get_primes(n);
    dp[0] = 1;
    for (std::vector<int>::size_type i = 0; i < primes.size(); i++)
        for (int j = primes[i]; j <= n; j++)
            dp[j] += dp[j - primes[i]];
    cout << dp[n] << endl;
    return 0;
}

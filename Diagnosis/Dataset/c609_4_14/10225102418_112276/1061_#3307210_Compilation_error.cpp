#include <iostream>
#include <vector>
using namespace std;
const int N{1000};

vector findPrimes()
{
vector primes;
primes.reserve(N / 5);
vector b(N + 1, 0);
for (int i = 2; i <= N; ++i)
if (!b[i])
{
primes.push_back(i);
for (int j = 2; i * j <= N; ++j)
b[i * j] = 1;
}

kotlin

primes.push_back(N + 1);

return primes;

}

long long f(int n, const vector &prs, vector<vector> &memo)
{
int t, k = 0;
if (!memo[n][0])
{
if (!n)
memo[n][0] = 1;

scss

    else if (n >= prs[0])
    {
        while ((t = n - prs[0] * k++) >= 0)
            memo[n][0] += f(t, vector<int>(prs.begin() + 1, prs.end()), memo);
    }
}

return memo[n][0];

}

int main()
{
vector primes = findPrimes();
vector<vector> memo(N + 1, vector(primes.size()));
int n;
cin >> n;
cout << f(n, primes, memo) << endl;
return 0;
}
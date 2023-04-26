#include <iostream>
#include <vector>

using namespace std;
const int N{1000};
int *findPrimes(int *prs)

{
    int i, j, *primes = prs;
    vector<int> b{vector<int>(N + 1, 0)};
    for (i = 2; i <= N; ++i)
        if (!b[i])
        {
            *prs++ = i;
            for (j = 2; i * j <= N; ++j)
                b[i * j] = 1;
        }

    *prs = N + 1;

    return primes;
}

long long
f(int n, int *prs)
{
    static vector<vector<long long>> m(N + 1, vector<long long>(N + 1));
    int t, k = 0;
    if (!m[n][*prs])

        if (!n)
            m[n][*prs] = 1;

        else if (n >= *prs)
            while ((t = n - *prs * k++) >= 0)
                m[n][*prs] += f(t, prs + 1);
    return m[n][*prs];
}

int main()

{
    int n, primes[N / 5];
    cout << f((cin >> n, n), findPrimes(primes)) << endl;
    return 0;
}
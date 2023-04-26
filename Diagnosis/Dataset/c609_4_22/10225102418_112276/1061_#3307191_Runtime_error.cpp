#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
const int N{1000};
vector<int> findPrimes(vector<int> prs)

{
    int i, j;
    vector<int> primes = prs;
    int iter = 0;
    vector<int> b{vector<int>(N + 1, 0)};
    for (i = 2; i <= N; ++i)
        if (!b[i])
        {
            prs[iter++] = i;
            for (j = 2; i * j <= N; ++j)
                b[i * j] = 1;
        }

    prs[iter] = N + 1;

    return primes;
}

long long
f(int n, vector<int> prs)
{
    static vector<vector<long long>> m(N + 1, vector<long long>(N + 1));
    int t, k = 0;
    int iter = 0;
    if (!m[n][prs[iter]])

        if (!n)
            m[n][prs[iter]] = 1;

        else if (n >= prs[iter])
            while ((t = n - prs[iter] * k++) >= 0)
            {
                vector<int> tmp;
                tmp.assign(prs.begin() + 1, prs.end());
                m[n][prs[iter]] += f(t, tmp);
            }
    return m[n][prs[iter]];
}

int main()

{
    int n;
    vector<int> primes{vector<int>(N / 5, 0)};
    cout << f((scanf("%d", &n), n), findPrimes(primes)) << endl;
    return 0;
}
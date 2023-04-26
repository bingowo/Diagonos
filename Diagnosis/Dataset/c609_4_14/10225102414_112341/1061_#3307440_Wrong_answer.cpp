#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N{1000};

vector<int> findPrimes(vector<int> &prs)
{
    int i, j;
    vector<int> b(1001, 0);
    for (i = 2;i <= N;i++)
        if (b[i] == 0){
            prs.push_back(i);
            for (j = 2;i * j <= N;j++) b[i * j] = 1;
        }
    prs.push_back(N + 1);
    return prs;
}

long long f(int n, vector<int>primes)
{
    static vector<vector<long long>> m(N + 1, vector<long long>(N + 1));
    int t, k = 0;
    primes.erase(primes.begin());
    vector<int>::iterator prs = primes.begin();
    if (!m[n][*prs]){
        if (!n) m[n][*prs] = 1;
        else if (n >= *prs){
            while((t = n - *prs * k++) >= 0)
                m[n][*prs] += f(t, primes);
        }
    }
    return m[n][*prs];
}

int main()
{
    int n;
    vector<int> primes;
    cin >> n;
    cout << f(n, findPrimes(primes)) << endl;
    return 0;
}

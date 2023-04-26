#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1000;

vector<int> findPrimes()
{
    vector<int> primes;
    vector<bool> b(N+1);
    for(int i = 2; i <= N; i++)
    {
        if(!b[i])
        {
            primes.push_back(i);
            for(int j = 2; i*j <= N; j++)
            {
                b[i*j] = true;
            }
        }
    }
    return primes;
}

long long f(int n, const vector<int>& primes)
{
    static vector<vector<long long>> m(N+1, vector<long long>(N+1));
    int t, k = 0;
    if(!m[n][0])
        if(!n) m[n][0] = 1;
        else if(n >= primes[0]) while((t = n - primes[k++]) >= 0) m[n][0] += f(t, vector<int>(primes.begin()+1, primes.end()));
    return m[n][0];
}

int main()
{
    int n;
    cin >> n;
    vector<int> primes = findPrimes();
    cout << f(n, primes) << endl;
    return 0;
}
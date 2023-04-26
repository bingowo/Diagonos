#include<bits/stdc++.h>
using namespace std;
#define N 1000

int *findPrimes(int *prs)
{
    int i, j, *primes=prs;
    vector<int> b(N+1);
    for(i=2; i<=N; i++)
    {
        if(!b[i])
        {
            *prs++ = i;
            for(j=2; i*j<=N; j++)
            {
                b[i*j]=1;
            }
        }
        *prs=N+1;
    }
    return primes;
}

long long f(int n, int *prs)
{
    static vector<vector<long long>> m(N+1, vector<long long>(N+1));
    int t, k=0;
    if(!m[n][*prs])
        if(!n)  m[n][*prs]=1;
        else if(n>=*prs)  while((t=n-*prs*k++)>=0) m[n][*prs]+=f(t, prs+1);
    return m[n][*prs];
}

int main()
{
    int n;
    vector<int> primes(N/5);
    cin >> n;
    cout << f(n, findPrimes(primes));
    return 0;
}
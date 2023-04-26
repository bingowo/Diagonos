#include <iostream>
#include <vector>
using namespace std;

const int N{1000};

vector<int>::iterator findPrimes(vector<int>& prs)
{ vector<int>b(N+1,0);
   for (int i=2;i<=N;i++) if (!b[i]) { prs.push_back(i); for (int j=2;i*j<=N;j++) b[i*j]=1;}
   prs.push_back(N+1);  return prs.begin();
}

long long f(int n, vector<int>::iterator prs)
{ static vector<vector<long long>> m(N+1,vector<long long>(N+1,0)); int t;
  if (!m[n][*prs])
    if (!n) m[n][*prs]=1;
    else if (n>=*prs) for (int k=0;(t=n-*prs*k)>=0;k++) m[n][*prs]+=f(t,prs+1);
  return m[n][*prs];
}

int main()
{ int n; vector<int> primes;findPrimes(primes);
   cout << f((cin>>n,n),findPrimes(primes)) << endl;
   return 0;
}
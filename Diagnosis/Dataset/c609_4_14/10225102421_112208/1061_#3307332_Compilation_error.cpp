include<vector>
const int N=1000;
using namespace std;
vector<int>::iterator findPrimes(vector<int>::iterator prs)
{
    int i,j,b[N+1]={0};
    vector<int>::iterator primes=prs;
    for (i=2;i<=N;i++) if (!b[i]){*prs++=i; for (j=2;i*j<=N;j++) b[i*j]=1;}
    *prs=N+1;
    return primes;
}
long long f(int n,vector<int>::iterator prs)
{
    static long long m[N+1][N+1];
    int t,k=0;
    if(!m[n][*prs])
        if(!n) m[n][*prs]=1;
        else if (n>=*prs) while((t=n-*prs*k++)>=0)
            m[n][*prs]+=f(t,prs+1);
    return m[n][*prs];
}
int main()
{
    int n;
    vector<int> primes(N/5);
    vector<int>::iterator PRIMES=primes.begin();
    cin>>n;
    cout<<f(n,findPrimes(PRIMES));
    return 0;
}
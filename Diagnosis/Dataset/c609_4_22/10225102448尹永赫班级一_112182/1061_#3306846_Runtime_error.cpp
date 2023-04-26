#include <iostream>
#include <string>
#include <vector>
const int N=1000;
using namespace std;
vector <int> qq(vector <int> q)
{
    int i,j,b[N+1]={0};
    vector <int> w=q;
    for (i=2;i<=N;i++) if (!b[i]) {q[i++]=i;for (j=2;i*j<=N;j++) b[i*j]=1;}
    q[i]=N+1; return w;
}
long long f(int n,vector <int> prs)
{
    static long long m[N+1][N+1]; int t,k=0,i=0;
    if (!m[n][prs[i]])
        if (!n)m[n][prs[i]]=1;
        else if (n>=prs[i]) while ((t=n-prs[i]*k++)>=0)
        {   vector<int>::iterator k = prs.begin();
            prs.erase(k);
            m[n][prs[i]]+=f(t,prs);
        }

     return m[n][prs[i]];
}
int main()
{
    int n;
    cin>>n;
     vector <int> primes;
    cout<< f(n,qq(primes))<<endl;
    return 0;
}
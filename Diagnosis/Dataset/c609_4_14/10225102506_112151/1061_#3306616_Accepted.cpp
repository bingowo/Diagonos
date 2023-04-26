#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N=1005;
vector<long long> dp(N);
vector<int> prime(N);

bool ck_prime(int x){
    for(int i=2;i*i<=x;i++){
            if(x%i==0)  return 0;
    }
    return 1;
}

int sieve(){
    vector<int>::iterator it=prime.begin();
    for(int i=2;i<N;i++){
        if(ck_prime(i)){
            *it=i;
            it++;
        }
    }
    return it-prime.begin();
}

int main(){
    int n;
    cin >> n;
    int np=sieve() ;
    dp[0]=1;
    for(int i=0;i<np && prime[i]<=n;i++){
        for(int j=prime[i];j<=n;j++){
            dp[j]+=dp[j-prime[i]];
        }
    }
    cout << dp[n] << endl;
    return 0;
}

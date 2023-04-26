#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

bool isprime(int a){
    for(int i = 2; i*i <= a; i++){
        if(a%i == 0) return false; 
    }
    return true;
}

void prime(vector<int>&a){
    for(int i = 2; i < 1002; i++)
        if(isprime(i))
            a.insert(a.end(),i);
}

int main(void)
{
    vector<int> p;
    prime(p);

    int in;
    cin >> in;

    long long dp[1001] = {1};
    for(int i = 0; i < p.size() && p[i] < in; i++){
        for(int v = p[i]; v <= in; v++){
            dp[v] += dp[v - p[i]];
        }
    }

    cout << dp[in] << endl;
    return 0;
}
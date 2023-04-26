#include<stdio.h>
#include<stdlib.h>
#define ll long long

ll mypow(ll a, ll b){
    ll res = 1;
    for (ll i = 1; i <= b; i++) {
        res *= a;
    }
    return res;
}

int main(){
    ll n, m;
    while(scanf("%lld %lld", &n, &m)!=EOF){
        if (n==-1&&m==-1) break;
        ll res = 0;
        for (ll i = n - m; i >= 0; i--) res += mypow(2, i);
        printf("%lld\n", res);
    }
    return 0;
}
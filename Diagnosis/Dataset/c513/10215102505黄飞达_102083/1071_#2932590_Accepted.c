#include<stdio.h>
#define p 10007
#define K 1000000

typedef long long ll;
ll a, b, k, n, m, fac[K+1];

void init()
{
    fac[0] = 1;
    for(int i = 1; i <= K; ++i)
        fac[i] = fac[i-1]*i % p;
}

ll pow_mod(ll a, ll x)
{
    ll ret = 1;
    while (x) {
        if (x & 1) ret = (ret * a) % p;
        a = (a * a) % p;
        x >>= 1;
    }
    return ret;
}

ll C(ll n, ll m)
{
    if(m > n) return 0;
    return fac[n] * pow_mod((fac[m]*fac[n-m])%p, p-2) % p;
}

int main()
{
    int cas;
    ll ans;
    scanf("%d", &cas);
    init();
    for (int t = 0; t < cas; ++t) {
        scanf("%lld%lld%lld%lld%lld", &a, &b, &k, &n, &m);
        ans = pow_mod(a, n);
        ans = (ans * pow_mod(b, m)) % p;
        ans = (ans * C(k, m)) % p;
        printf("case #%d:\n%lld\n", t, ans);
    }
    return 0;
}
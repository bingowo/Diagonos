#include <stdio.h>
#include <stdlib.h>
#define P 10007

typedef long long ll;

ll pow_mod(ll a, ll x, int p)
{
    ll ret = 1;
    while(x) {
        if (x & 1) ret = ret * a % p;
        a = a * a % p;
        x >>= 1;
    }
    return ret;
}

ll comb(ll a, ll b, int p)
{
    if (a < b) return 0;
    if (a == b) return 1;
    if (b > a - b) b = a - b;
    ll ans = 1, ca = 1, cb = 1;
    for (ll i = 0; i < b; ++i) {
        ca = (ca * (a - i)) % p;
        cb = (cb * (b - i)) % p;
    }
    ans = (ca * pow_mod(cb, p-2, p)) % p;
    return ans;
}

ll lucas(ll n, ll m, int p)
{
    ll ans = 1;
    while(n && m && ans) {
        ans = (ans * comb(n%p, m%p, p)) % p;
        n /= p;
        m /= p;
    }
    return ans;
}

int main()
{
    int cas, k;
    ll a, b, n, m;
    scanf("%d",&cas);
    for (int t = 0; t < cas; ++t) {
        scanf("%lld%lld%d%lld%lld",&a,&b,&k,&n,&m);
        printf("case #%d:\n", t);
        if (n + m != k) printf("0\n");
        else {
            ll ans = pow_mod(a, n, P);
            ans = (ans * pow_mod(b, m, P)) % P;
            ans = (ans * lucas(k, n, P)) % P;
            printf("%lld\n",ans);
        }
    }
    return 0;
}
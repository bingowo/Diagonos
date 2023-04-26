#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define mod 10007
long long f[1000001];
void init() {
    for (long long i = 0; i < 1000001; i++) {
        if (!i || i == 1)
            f[i] = 1;
        else
            f[i] = f[i - 1] * i % mod;
    }
}
long long qpow(long long a, long long n) {
    long long ans = 1;
    while (n) {
        if (n & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}

int main()
{
    int T;
    scanf("%d",&T);
    int a,b,k,n,m;
    for(int cas=0;cas<T;cas++)
    {
        scanf("%d %d %d %d %d",&a,&b,&k,&n,&m);
        printf("case #%d:\n",cas);
        long long res = qpow(a, n) * qpow(b, m) % mod;
        long long res2 = f[k] * qpow(f[m] * f[k - m] % mod, mod - 2) % mod;
        res = res * res2 % mod;
        printf("%d\n",res);
    }
    return 0;
}

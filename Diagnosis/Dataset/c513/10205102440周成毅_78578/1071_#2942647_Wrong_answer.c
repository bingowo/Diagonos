#include <stdio.h>

int main() {
    unsigned long long a, b; int k, n, m,T;
    scanf("%d",&T);
    for(int j=0;j<T;j++){
        scanf("%llu %llu %d %d %d", &a, &b, &k, &n, &m);
        if(a>10007)
            a%=10007;
        if(b>10007)
            b%=10007;
        int N = m > n ? n : m;
        int K = k;
        unsigned long long yu = 1;
        for (int i = 1; i <= N; i++, K--) {
            yu = yu * K / i;
            yu %= 10007;
        }
        for (int i = 0; i < n; i++) {
            yu = yu * a;
            if(yu>10007)
                yu %= 10007;
        }
        for (int i = 0; i < m; i++) {
            yu = yu * b;
            if(yu>10007)
                yu %= 10007;
        }
        printf("case #%d:\n%llu\n",j,yu);
    }
    return 0;
}
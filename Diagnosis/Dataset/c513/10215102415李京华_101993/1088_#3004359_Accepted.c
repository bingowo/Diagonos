#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void f(int m, int n) {
    if (n > m/2) {
        f(m, m-n);
        return ;
    }

    if (n == 0) {
        printf("1\n");
        return ;
    }
    if (n == 1) {
        printf("%d\n", m);
        return ;
    }

    int a[n], b[n];
    for (int i = n; i > 0; --i) {
        b[i - 1] = i;
        a[i - 1] = m - n + i; 
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            while (a[i] % 2 == 0 && b[j] % 2 == 0) {
                a[i] /= 2;
                b[j] /= 2;
            }
            while (a[i] % 3 == 0 && b[j] % 3 == 0) {
                a[i] /= 3;
                b[j] /= 3;
            }

            while(a[i] % 5 == 0 && b[j] % 5 == 0) {
                a[i] /= 5;
                b[j] /= 5;
            }
        }
    }

    long long ans = 1;
    for (int i = 0; i < n; ++i) {
        ans *= a[i];
    }

    for (int i = 0; i < n; ++i)
        ans /= b[i];

    printf("%lld\n", ans);
}

void Solve() {
    int m, n;
    scanf("%d%d", &m, &n);
    f(m, n);
}

int main() {
    int n, k = 0;
    scanf("%d" ,&n);
    while (n--) {
        printf("case #%d:\n", k++);
        Solve();
    }
    return 0;
}
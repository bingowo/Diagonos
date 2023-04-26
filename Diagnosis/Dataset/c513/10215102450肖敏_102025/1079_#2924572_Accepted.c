#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    long long *a1 = (long long *) a, *b1 = (long long *) b;
    if (*a1 > *b1)
        return 1;
    return -1;
}
int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int n, m;
        int a[1001] = {0};
        scanf("%d", &n);
        scanf("%d", &m);
        long long int b[500501] = {0};
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            scanf("%d", a + j);
            a[j] += a[j - 1];
        }
        for (int len = 1; len <= n; len++)
            for (int x = 1; x <= n - len + 1; x++)
                b[++cnt] = a[x + len - 1] - a[x - 1];
        qsort(b, n * (n + 1) / 2, sizeof(b[0]), cmp);
        for (int x = 1; x <= cnt; x++) b[x] += b[x - 1];
        printf("case #%d:\n", i);
        for (int k = 0; k < m; k++) {
            int L, U;
            scanf("%d%d", &L, &U);
            printf("%lld\n", b[U] - b[L - 1]);
        }
    }
    return 0;
}

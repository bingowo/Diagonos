#include <stdio.h>

int main() {
    int t, T;
    scanf("%d", &T);
    for (t = 0; t < T; ++t) {
        int n;
        scanf("%d", &n);
        long long a[4];
        a[0] = 0;
        a[1] = 1;
        a[2] = 1;
        long long ans;
        if (n < 3)
            ans = a[n];
        else {
            for (int i = 2; i < n; i++) {
            a[3] = a[0] + a[1] + a[2];
            a[0] = a[1];
            a[1] = a[2];
            a[2] = a[3];
            }
            ans = a[3];
        }
        printf("case #%d:\n", t);
        printf("%lld\n", ans);
    }
    return 0;
}
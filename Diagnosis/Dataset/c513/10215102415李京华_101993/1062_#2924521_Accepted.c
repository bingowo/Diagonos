#include <stdio.h>

int main() {
    int t, T;
    scanf("%d", &T);
    for (t = 0; t < T; ++t) {
        int n;
        scanf("%d", &n);

        long long ans;
        long long a[5];
        a[0] = 1;
        a[1] = 2;
        a[2] = 4;
        a[3] = 8;

        if (n < 5)
            ans = a[n-1];
        else {
            for (int i = 4; i < n; i++) {
                a[4] = a[0] + a[1] + a[2] + a[3];
                a[0] = a[1];
                a[1] = a[2];
                a[2] = a[3];
                a[3] = a[4];
            }
            ans = a[4];
        }
        printf("case #%d:\n", t);
        printf("%lld\n", ans);
    }
}
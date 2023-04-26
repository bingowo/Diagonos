#include <stdio.h>

int main() {
    int a, n, m, x;
    scanf("%d%d%d%d", &a, &n, &m, &x);
    int ans = a;
    for (int i = 2; i <= x; i++) {
        ans += a;
        a = ans - a;
        if (i == n) ans -= m;
    }
    printf("%d\n", ans);
    return 0;
}

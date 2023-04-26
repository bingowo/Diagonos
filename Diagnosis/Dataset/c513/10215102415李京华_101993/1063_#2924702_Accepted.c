#include <stdio.h>

int main() {
    long long x, y;
    scanf("%lld%lld", &x, &y);
    long long ans = 0;
    if (x < y) {
        long long tmp = x;
        x = y;
        y = tmp;
    }

    while (x % y != 0) {
        ans += (x / y) * 4 * y;
        long long tmp = x - (x / y) * y;
        x = y;
        y = tmp;
    }

    ans += (x / y) * 4 * y;
    printf("%lld", ans);
    return 0;
}
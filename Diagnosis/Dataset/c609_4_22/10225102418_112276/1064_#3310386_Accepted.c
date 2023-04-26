#include <stdio.h>

int main() {
    long long x, y;
    scanf("%lld %lld", &x, &y);
    long long ans = 0;
    while (y) {
        ans += x / y * y * 4;
        long long tmp = x % y;
        x = y;
        y = tmp;
    }
    printf("%lld\n", ans);
    return 0;
}
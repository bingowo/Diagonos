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
        ans += 4 * x;
        x = y;
        y = y % x;
    }
    
    ans += (x / y) * 4 * y;
    printf("%lld", ans);
    return 0;
}
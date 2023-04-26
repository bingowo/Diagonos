#include <stdio.h>

int main() {
    long long x, y;
    scanf("%lld%lld", &x, &y);
    long long min = 0;
    long long temp;
    while (x && y) {
        if (x < y) {
            temp = x;
            x = y;
            y = temp;
        }
        min += 4 * y * (x / y);
        x %= y;
    }
    printf("%lld\n", min);
    return 0;
}

#include <stdio.h>
#include <math.h>

long long a, b;

long long f(long long n) {
    long long k = (long long) sqrt(n);
    if (k * k > n)
        k--;
    long long bian;
    int state = 0;
    if (n <= k * (k + 1)) {
        bian = k;
        state = 0;
    } else {
        bian = k + 1;
        state = 1;
    }
    long long y = bian / 2;
    long long q;
    if (state == 0) {
        if (bian % 2 == 0) {
            q = (-1) * y;
            a = q + n - bian * bian;
            b = (-1) * y;
        } else {
            q = y;
            a = q - n + bian * bian;
            b = y + 1;
        }
    } else {
        if (bian % 2 == 0) {
            q = y;
            a = (-1) * y;
            b = q - n + bian * (bian - 1);
        } else {
            q = (-1) * y;
            a = y;
            b = q + n - bian * (bian - 1);
        }
    }
}

int main() {
    long long n;
    scanf("%lld", &n);
    f(n);
    printf("(%lld,%lld)\n", a, b);
    return 0;
}
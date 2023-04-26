#include <stdio.h>
#include <string.h>

#define MAXN 5000

typedef struct {
    int len;
    int s[MAXN];
} BigNumber;

void printBigNumber(BigNumber num) {
    for (int i = num.len - 1; i >= 0; i--) {
        printf("%d", num.s[i]);
    }
}

BigNumber add(BigNumber a, BigNumber b) {
    BigNumber c;
    memset(c.s, 0, sizeof(c.s));
    int carry = 0;
    int len = a.len > b.len ? a.len : b.len;
    for (int i = 0; i < len; i++) {
        int tmp = a.s[i] + b.s[i] + carry;
        c.s[c.len++] = tmp % 10;
        carry = tmp / 10;
    }
    if (carry != 0) {
        c.s[c.len++] = carry;
    }
    return c;
}

BigNumber fib(int n) {
    BigNumber a, b, c;
    a.len = b.len = 1;
    a.s[0] = 0;
    b.s[0] = 1;
    for (int i = 2; i <= n; i++) {
        c = add(a, b);
        a = b;
        b = c;
    }
    return a;
}

int main() {
    int n;
    scanf("%d", &n);
    printBigNumber(fib(n));
    return 0;
}

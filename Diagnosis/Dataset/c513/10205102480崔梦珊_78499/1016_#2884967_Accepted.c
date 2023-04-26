#include <stdio.h>

char *digit = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
    int n, r;
    scanf("%d%d", &n, &r);
    int ans[33], sz = 0, x;
    do {
        x = (n % r - r) % r;
        ans[sz++] = x;
    } while (n = (n - x) / r);
    for (int i = sz - 1; ~i; i--) {
        printf("%c", digit[ans[i]]);
    }
    putchar('\n');
}
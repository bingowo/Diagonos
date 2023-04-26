#include <stdio.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);
    while (n != 0) {
        int k = n * log10(n);
        int ans = pow(10, n * log10(n) - k);
        printf("%d\n", ans);
        scanf("%d", &n);
    }
    return 0;
}
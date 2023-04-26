#include <stdio.h>

void Solve() {
    int n;
    scanf("%d", &n);
    int ans = 0;
    while (n) {
        n /= 5;

        ans += n;
    }
    printf("%d\n", ans);
}

int main() {
    int n, k = 0;
    scanf("%d", &n);
    while (n--) {
        printf("case #%d:\n", k++);
        Solve();
    }
    return 0;
}
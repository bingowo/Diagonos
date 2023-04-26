#include <stdio.h>

int reverse(int n) {
    int ret = 0;
    while (n) {
        ret = ret*10 + n % 10;
        n /= 10;
    }
    return ret;
}

int isReverse(int n) {
    return (reverse(n) == n) ? 1 : 0;
}

int main() {
    int n;
    scanf("%d", &n);
    int cnt = 0;
    int ans;
    do {
        // printf("n = %d, reverse(n) = %d\n", n, reverse(n));
        cnt++;
        ans = reverse(n);
        n += ans;
    }while (!isReverse(n));
    ans += reverse(ans);
    printf("%d %d", cnt, ans);
    return 0;
}
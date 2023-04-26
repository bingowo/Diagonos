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
    int rev;
    do {
        cnt++;
        rev = reverse(n);
        n += rev;
    }while (!isReverse(n));
    printf("%d %d", cnt, n);
    return 0;
}
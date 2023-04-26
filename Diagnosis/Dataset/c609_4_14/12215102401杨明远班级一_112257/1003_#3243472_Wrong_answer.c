#include <stdio.h>

void convert(int n) {
    if (n == 0) {
        return;
    }
    convert(n / 2333);
    printf("%d ", n % 2333);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        long long n;
        scanf("%lld", &n);
        if (n == 0) {
            printf("0\n");
        }
        else {
            convert(n);
            printf("\n");
        }
    }
    return 0;
}
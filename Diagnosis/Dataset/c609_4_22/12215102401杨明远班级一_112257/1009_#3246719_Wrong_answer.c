#include <stdio.h>
#define N 1000
int main() {
    int n;
    scanf("%d", &n);

    char str[N];
    for (int i = 0; i < n; i++) {
        fgets(str, sizeof(str), stdin);
        int ones = 0;
        int size = 0;
        for (int j = 0; str[j] != '\0'; j++) {
            if (str[j] == '\n') {
                continue;
            }
            ones += __builtin_popcount(str[j]);
            size += 8;
        }
        int gcd = 1;
        for (int j = 2; j <= ones && j <= size; j++) {
            if (ones % j == 0 && size % j == 0) {
                gcd = j;
            }
        }
        printf("%d/%d\n", ones / gcd, size / gcd);
    }

    return 0;
}

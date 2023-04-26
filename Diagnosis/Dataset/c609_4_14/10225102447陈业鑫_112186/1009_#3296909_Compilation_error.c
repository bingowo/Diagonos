#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        char c;
        while ((c = getchar()) != '\n') {
            for (int j = 7; j >= 0; --j) {
                if (c & (1 << j)) {
                    ++cnt;
                }
            }
        }

        int gcd = 1;
        int denominator = 8 * strlen(buffer) ;
        int numerator = cnt;
        for (int j = 1; j <= denominator; ++j) {
            if (numerator % j == 0 && denominator % j == 0) {
                numerator /= j;
                denominator /= j;
                gcd *= j;
                j = 1;
            }
        }
        printf("%d/%d\n", numerator, denominator);
    }
    return 0;
}
#include <string.h>

char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void convert(int n, int r) {
    char result[50];
    int i = 0;

    while (n) {
        result[i++] = digits[n % r];
        n /= r;
    }
    result[i] = '\0';

    strrev(result);
    printf("%s\n", result);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, r;
        scanf("%d%d", &n, &r);
        convert(n, r);
    }
    return 0;
}
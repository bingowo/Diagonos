#include <stdio.h>
#include <string.h>

void decimal_to_base(int n, int r, char* result) {
    char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i = 0;
    if (n == 0) {
        result[0] = '0';
        result[1] = '\0';
        return;
    }
    while (n > 0) {
        int digit = n % r;
        result[i++] = digits[digit];
        n /= r;
    }
    result[i] = '\0';
    strrev(result);  // 翻转字符串
}

int main() {
    int t, n, r;
    char result[100];
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &r);
        decimal_to_base(n, r, result);
        printf("%s\n", result);
    }
    return 0;
}
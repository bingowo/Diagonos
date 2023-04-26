#include <stdio.h>
#include <string.h>
#include <gmp.h>

#define BASE 62

void to_num(char *str, mpz_t num) {
    int len = strlen(str);
    for (int i = len - 1; i >= 0; i--) {
        int digit = 0;
        if ('0' <= str[i] && str[i] <= '9') {
            digit = str[i] - '0';
        } else if ('a' <= str[i] && str[i] <= 'z') {
            digit = str[i] - 'a' + 10;
        } else if ('A' <= str[i] && str[i] <= 'Z') {
            digit = str[i] - 'A' + 36;
        }
        mpz_mul_ui(num, num, BASE);
        mpz_add_ui(num, num, digit);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        char str[61];
        scanf("%s", str);
        mpz_t num;
        mpz_init(num);
        to_num(str, num);
        gmp_printf("case #%d:\n%Zd\n", t, num);
        mpz_clear(num);
    }
    return 0;
}

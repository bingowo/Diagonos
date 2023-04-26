#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LEN 60
#define MAX_SYMBOLS 62

int main()
{
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        char mystery[MAX_LEN + 1];
        scanf("%s", mystery);

        long long value = 0;
        int base = 0;
        int count[MAX_SYMBOLS] = {0};
        for (int j = 0; j < strlen(mystery); j++) {
            char symbol = mystery[j];
            int digit;
            if (symbol >= '0' && symbol <= '9') {
                digit = symbol - '0';
            } else if (symbol >= 'a' && symbol <= 'z') {
                digit = symbol - 'a' + 10;
            } else if (symbol >= 'A' && symbol <= 'Z') {
                digit = symbol - 'A' + 36;
            }
            if (digit > base) {
                base = digit;
            }
            count[digit]++;
        }

        if (base == 0) {
            base = 1;
        }

        int used[MAX_SYMBOLS] = {0};
        used[0] = 1;
        for (int j = base + 1; j <= MAX_SYMBOLS && value == 0; j++) {
            if (count[j - 1] > 0 && !used[j % base]) {
                int digits[MAX_LEN] = {0};
                int numDigits = 0;
                int remainder = 0;
                for (int k = 0; k < strlen(mystery); k++) {
                    char symbol = mystery[k];
                    int digit;
                    if (symbol >= '0' && symbol <= '9') {
                        digit = symbol - '0';
                    } else if (symbol >= 'a' && symbol <= 'z') {
                        digit = symbol - 'a' + 10;
                    } else if (symbol >= 'A' && symbol <= 'Z') {
                        digit = symbol - 'A' + 36;
                    }
                    if (digit == j - 1) {
                        digits[numDigits++] = remainder;
                        remainder = 0;
                    } else {
                        remainder = remainder * base + digit;
                    }
                }
                digits[numDigits++] = remainder;

                int valid = 1;
                for (int k = 0; k < MAX_SYMBOLS; k++) {
                    if (count[k] > 0 && (k % base) >= numDigits) {
                        valid = 0;
                        break;
                    }
                }
                if (valid) {
                    long long tempValue = 0;
                    for (int k = numDigits - 1; k >= 0; k--) {
                        tempValue = tempValue * j + digits[k];
                    }
                    if (value == 0 || tempValue < value) {
                        value = tempValue;
                    }
                    used[j % base] = 1;
                }
            }
        }

        printf("case #%d:\n%lld\n", i, value);
    }

    return 0;
}

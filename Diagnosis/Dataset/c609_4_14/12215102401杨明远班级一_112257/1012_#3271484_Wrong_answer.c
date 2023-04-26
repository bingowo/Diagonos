#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 150

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        char octal[MAX_DIGITS];
        scanf("%s", octal);

        // convert octal to decimal
        int len = strlen(octal);
        double decimal = 0;
        for (int j = 2; j < len; j++) {
            decimal += (octal[j] - '0') * pow(8, -(j - 1));
        }

        // output the result
        printf("case #%d: %.10lf\n", i, decimal);
    }

    return 0;
}

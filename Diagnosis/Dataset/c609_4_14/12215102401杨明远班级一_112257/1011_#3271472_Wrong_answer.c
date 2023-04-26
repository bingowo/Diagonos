#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    char balancedTernary[100];
    int decimal = 0;
    int sign = 1;
    int len, i;

    scanf("%s", balancedTernary);

    len = strlen(balancedTernary);

    for (i = 0; i < len; i++) {
        if (balancedTernary[i] == '-') {
            sign = -1;
        } else if (balancedTernary[i] == '0') {
            decimal += 0;
        } else if (balancedTernary[i] == '1') {
            decimal += sign*pow(3, len-i-1);
            sign = 1;
        } else if (balancedTernary[i] == '2') {
            decimal += -1*sign*pow(3, len-i-1);
            sign = 1;
        }
    }

    if (decimal < 0) {
        printf("-%d %d %d\n", abs(decimal)/3, abs(decimal)%3, 3);
    } else if (decimal == 0) {
        printf("0\n");
    } else {
        printf("%d %d %d\n", decimal/3, decimal%3, 3);
    }

    return 0;
}

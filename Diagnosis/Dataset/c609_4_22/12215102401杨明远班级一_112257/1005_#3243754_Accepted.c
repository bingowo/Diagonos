#include <stdio.h>
#include <string.h>

int balancedTernaryToDecimal(char *balancedTernary) {
    int n = strlen(balancedTernary);
    int decimal = 0;
    for (int i = 0; i < n; i++) {
        char c = balancedTernary[i];
        if (c == '-') {
            decimal -= 1;
        } else if (c == '0') {
            // do nothing
        } else if (c == '1') {
            decimal += 1;
        }
        if (i < n - 1) {
            decimal *= 3;
        }
    }
    return decimal;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        char balancedTernary[100];
        scanf("%s", balancedTernary);
        int decimal = balancedTernaryToDecimal(balancedTernary);
        printf("case #%d:\n%d\n", i, decimal);
    }
    return 0;
}

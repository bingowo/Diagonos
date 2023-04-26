#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double expr() {
    char s[11];
    double f1, f2;
    scanf("%s", s);
    switch (s[0]) {
        case '+':
            f1 = expr();
            f2 = expr();
            return f1 + f2;
        case '-':
            f1 = expr();
            f2 = expr();
            return f1 - f2;
        case '*':
            f1 = expr();
            f2 = expr();
            return f1 * f2;
        case '/':
            f1 = expr();
            f2 = expr();
            return f1 / f2;
        default:
            return atof(s);
    }
}

int main() {
    int t, T;    
    scanf("%d\n", &T);
    for (t = 0; t < T; t++) {
        double ans = expr();
        printf("case #%d:\n", t);
        printf("%.6f\n", ans);
    }
    return 0;
}
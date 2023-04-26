#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_N 100

double stack[MAX_N];
int top = -1;

void push(double x) {
    stack[++top] = x;
}

double pop() {
    return stack[top--];
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        char s[MAX_N];
        scanf("%s", s);
        int len = strlen(s);
        top = -1;
        double a, b;
        for (int j = len - 1; j >= 0; j--) {
            if (isdigit(s[j])) {
                double num = 0, base = 1;
                while (isdigit(s[j])) {
                    num += (s[j] - '0') * base;
                    base *= 10;
                    j--;
                }
                push(num);
            } else {
                a = pop();
                b = pop();
                switch (s[j]) {
                    case '+': push(a + b); break;
                    case '-': push(a - b); break;
                    case '*': push(a * b); break;
                    case '/': push(a / b); break;
                }
            }
        }
        printf("case #%d:\n%.6f\n", i, stack[top]);
    }
    return 0;
}

#include <stdio.h>
#include <string.h>

#define MAX_N 105

int main() {
    char s[MAX_N], stack[MAX_N];
    int top = 0;
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        if (top > 0 && stack[top-1] == s[i]) {
            top--;
            stack[top] = s[i] * 2;
        } else {
            stack[top++] = s[i];
        }
    }
    stack[top] = '\0';
    printf("%s\n", stack);
    return 0;
}

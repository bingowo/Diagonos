#include <stdio.h>

int main() {
    char s[51];
    scanf("%s", s);
    int sum = 0, count = 1;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == s[i + 1] || s[i + 1] == '\0') {
            if (count > sum)
                sum = count;
            count = 1;
        } else count++;
    }
    printf("%d\n", sum);
    return 0;
}

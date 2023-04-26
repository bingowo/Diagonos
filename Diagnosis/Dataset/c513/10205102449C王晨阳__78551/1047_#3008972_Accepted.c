#include <stdio.h>

int main() {
    int T;
    char s[501];
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%s", s);
        char c = s[0];
        int len = 1;
        printf("case #%d:\n", i);
        for (int i = 1; s[i]; i++) {
            if (s[i] == c && len < 255)
                len++;
            else {
                printf("%d%c", len, c);
                c = s[i];
                len = 1;
            }
        }
        printf("%d%c\n", len, c);
    }
    return 0;
}

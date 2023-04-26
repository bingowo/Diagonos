#include <stdio.h>
#include <string.h>

int main() {
    char s[51];
    scanf("%s", s);
    int length = strlen(s);
    int i = 0;
    int a = 1, b = 1;
    while (i != length - 1) {
        if (s[i] != s[i + 1]) {
            if (i + 1 == length - 1) {
                b++;
                if (b > a) a = b;
                i++;
            } else {
                b++;
                i++;
            }
        } else {
            if (b > a) {
                a = b;
                i++;
                b = 1;
            } else {
                i++;
                b = 1;
            }
        }
    }
    printf("%d\n", a);
    return 0;
}

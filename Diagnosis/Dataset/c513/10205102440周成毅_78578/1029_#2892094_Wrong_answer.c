#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isLetter(char c) {
    return (c >= 'A' && c <= 'Z');
}

void mygets(char *s) {
    int i = 0;
    char a;
    while ((a = getchar()) != EOF && i < 121) {
        s[i++] = a;
        if (a == '\n')
            break;
    }
    s[--i] = '\0';
}

void sort(char *s, int len) {
    for (int i = 0; i < len - 1; i++) {
        if (!isLetter(s[i]))
            continue;
        for (int j = i + 1; j < len; j++) {
            if (!isLetter(s[j]))
                continue;
            if (s[i] > s[j]) {
                char tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;
            }
        }
    }
}

int main() {
    int T;
    char s[201];
    scanf("%d", &T);
    mygets(s);
    for (int i = 0; i < T; i++) {
        mygets(s);
        int len = strlen(s);
        sort(s, len);
        printf("case #%d:\n", i);
        printf("%s\n", s);
    }
    return 0;
}

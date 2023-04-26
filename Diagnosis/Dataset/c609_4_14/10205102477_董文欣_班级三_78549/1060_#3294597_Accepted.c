#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *insert(char *s, int pos) {
    for (int i = strlen(s) + 1; i > pos; i--) {
        s[i] = s[i-1];
    }
    return s;
}

int main()
{
    char s[201], t[201];
    scanf("%s", s);
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        insert(strcpy(t,s), i);
        if (strcmp(t, s) < 0) {
            len++;
            i++;
            strcpy(s, t);
        }
    }
    printf("%s", s);
    return 0;
}

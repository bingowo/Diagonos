#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define CHARNUM 26

int table[128];

int my_strcmp(char* s, char* t) {
    int i = 0;
    for (; s[i] && t[i] && table[toupper(s[i])] == table[toupper(t[i])]; ++i)
        ;
    if (s[i] && t[i]) {
        int temp = table[toupper(s[i])] - table[toupper(t[i])];
        if (temp > 0)
            return 1;
        else
            return -1;
    } else if (s[i])
        return 1;
    else if (t[i])
        return -1;
    else
        return 0;
}

int cmp(const void* p1, const void* p2) {
    return my_strcmp(*(char(*)[20])p1, *(char(*)[20])p2);
}

int main() {
    while (1) {
        char character[CHARNUM + 1];
        scanf("%s", character);
        getchar();
        for (int i = 0; i != CHARNUM; ++i)
            table[character[i]] = i;
        char s[100][20], c;
        int row_len = 0;
        do {
            scanf("%s", s[row_len++]);
        } while ((c = getchar()) != '\n' && c != EOF);
        qsort(s, row_len, sizeof(s[0]), cmp);
        for (int i = 0; i != row_len; ++i)
            printf("%s%c", s[i], i == row_len - 1 ? '\n' : ' ');
        if (c == EOF) break;
    }
    return 0;
}
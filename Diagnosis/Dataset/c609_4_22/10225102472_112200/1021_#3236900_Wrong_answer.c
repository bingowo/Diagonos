#include <stdio.h>
#include <string.h>

int table[130];

typedef struct {
    char s[25];
} Str;

int cmp(const void* a, const void* b) {
    Str* s1 = (Str*)a;
    Str* s2 = (Str*)b;
    int len1 = strlen(s1->s);
    int len2 = strlen(s2->s);
    int minLen = len1 < len2 ? len1 : len2;
    for (int i = 0; i < minLen; ++i) {
        if (s1->s[i] != s2->s[i]) {
            return table[s1->s[i]] < table[s2->s[i]];
        }
    }
    return len1 < len2;
}

int main() {
    char ch;
    while (scanf("%c", &ch) == 1) {
        memset(table, 0, sizeof(table));
        for (int i = 0; i < 52; i += 2) {
            table[ch] = i;
            table[ch + 32] = i + 1;
            scanf("%c", &ch);
        }
        Str strs[110];
        int strN = 0, j = 0;
        while (scanf("%c", &ch) == 1) {
            if (ch == '\n') {
                break;
            }
            if (ch == ' ') {
                strs[strN].s[j] = '\0';
                ++strN;
                j = 0;
            } else {
                strs[strN].s[j++] = ch;
            }
        }
        strs[strN].s[j] = '\0';
        qsort(strs, strN + 1, sizeof(Str), cmp);
        for (int i = 0; i <= strN; ++i) {
            printf("%s%c", strs[i].s, i == strN ? '\n' : ' ');
        }
    }
    return 0;
}

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* p1, const void* p2) {
    char c_1 = *(char*)p1, c_2 = *(char*)p2;
    return c_1 - c_2;
}

int main() {
    int T;
    scanf("%d", &T);
    getchar();
    for (int i = 0; i != T; ++i) {
        char s[201], t[201], c;
        int slen = 0, tlen = 0;
        while ((c = getchar()) != '\n') {
            if (isalpha(c))
                t[tlen++] = c;
            s[slen++] = c;
        }
        qsort(t, tlen, sizeof(char), cmp);
        printf("case #%d:\n", i);
        for (int i = 0, j = 0; i != slen; ++i) {
            if (isalpha(s[i])) {
                printf("%c", t[j]);
                ++j;
            } else
                printf("%c", s[i]);
        }
        printf("\n");
    }
}
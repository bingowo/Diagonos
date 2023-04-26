#include <stdio.h>
#include <stdlib.h>

int p[256];   //1-26
char s[100];

int cmp(const void *a, const void *b) {
    char *pa, *pb;
    pa = (char *) a, pb = (char *) b;
    while ((*pa) && (*pb)) {
        char tempA = *pa, tempB = *pb;
        if (p[tempA] > p[tempB]) return 1;
        if (p[tempA] < p[tempB]) return -1;
        pa++, pb++;
    }
    if (*pa) return 1;
    if (*pb) return -1;
    return 0;
}


int main() {
    while (scanf("%s\n", s) != EOF) {
        /**< initialize */
        char str[101][21];
        int i = 0, j = 0;
        for (int t = 0; t < 26; t++) {
            p[s[t]] = t;
            p[s[t] + 'a' - 'A'] = t;
        }
        /**< input string */
        char c;
        while ((c = getchar()) != '\n') {
            if (c == ' ') {
                c = getchar();
                str[i++][j] = '\0';
                j = 0;
            }
            str[i][j++] = c;
        }
        str[i++][j] = '\0';

        /**< sort */
        qsort(str, i, sizeof(str[0]), cmp);

        /**< output */
        printf("%s", str[0]);
        for (int k = 1; k < i; k++) {
            printf(" %s", str[k]);
        }
        printf("\n");
    }
    return 0;
}
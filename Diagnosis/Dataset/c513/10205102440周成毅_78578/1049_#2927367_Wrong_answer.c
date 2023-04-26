#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int trans(char (*target)[17], char *s) {
    int m = 0, n = 0;
    for (int i = 0; s[i]; i++) {
        if (islower(s[i])) {
            target[m][n++] = s[i];
            continue;
        } else {
            target[m][n] = '\0';
            m++;
            n = 0;
        }
    }
    if (n != 0) {
        target[m][n] = '\0';
        m++;
    }
    return m;
}

int cmp(const void *a, const void *b) {
//    char *a1=(char *)a;
//    char *b1=(char *)b;
    return strcmp((char *) a, (char *) b);
}

int main() {
    int T;
    char s[501];
    char target[200][17];
    scanf("%d", &T);
    getchar();
    for (int i = 0; i < T; i++) {
        gets(s);
        int len = trans(target, s);
        qsort(target, len, sizeof(target[0]), cmp);
        printf("case #%d:\n", i);
        printf("%s ", target[0]);
        for (int j = 1; j < len; j++) {
            if (strcmp(target[j - 1], target[j]))
                printf("%s ", target[j]);
        }
        printf("\n");
    }
    return 0;
}

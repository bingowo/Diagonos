#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct alp {
    int count;
    char s[21];
};

int cmp(const void *a, const void *b) {
    struct alp *a1 = (struct alp *) a, *b1 = (struct alp *) b;
    if (a1->count != b1->count)
        return b1->count - a1->count;
    else
        return strcmp(a1->s, b1->s);
}

int main() {
    struct alp A[100];
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        int n;
        int table[26];
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            memset(table, 0, sizeof(table));
            scanf("%s", A[i].s);
            A[i].count = 0;
            int len = strlen(A[i].s);
            for (int j = 0; j < len; j++) {
                if (table[A[i].s[j] - 'A'] == 0) {
                    A[i].count++;
                    table[A[i].s[j] - 'A'] = 1;
                }

            }
        }
        qsort(A, n, sizeof(A[0]), cmp);
        printf("case #%d:\n", t);
        for (int z = 0; z < n; z++) {
            printf("%s\n", A[z].s);
        }
    }
    return 0;
}

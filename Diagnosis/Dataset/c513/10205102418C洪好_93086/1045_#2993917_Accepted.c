#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    char c[256];
    char f[256];
    int n;
} StringCN;

StringCN tables[200000];
int t[256][200000];

void unique_count(char *s, StringCN *tb) {
    int len = strlen(s);
    if(len == 0) return;
    char t = s[0];
    int n = 1;
    int j = 0;
    for(int i = 1; i < len; ++i) {
        if(s[i] != t) {
            tb->f[j] = n;
            tb->c[j] = t;
            t = s[i];
            n = 1;
            j++;
        } else {
            n++;
        }
    }
    tb->f[j] = n;
    tb->c[j] = t;
    j++;
    tb->n = j;
}

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; ++i) {
        char s[256];
        scanf("%s", s);
        unique_count(s, &tables[i]);
        if(i != 0 && strcmp(tables[i].c, tables[0].c) != 0) {
            printf("-1");
            return 0;
        }
    }

    for(int i = 0; i < tables[0].n; i++) {
        for(int j = 0; j < T; j++) {
            t[i][j] = tables[j].f[i];
        }
    }

    int r = 0;
    for(int i = 0; i < tables[0].n; ++i) {
        qsort(t + i, T, sizeof(int), cmp);
        int m = t[i][T / 2];
        for(int j = 0; j < T; ++j) {
            r += abs(t[i][j] - m);
        }
    }
    printf("%d\n", r);

    return 0;
}
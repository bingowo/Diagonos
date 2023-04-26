#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Abt {
    double fre;
    char let;
} abt;

int cmp(const void* e1, const void* e2) {
    abt* m, *n;
    m = (abt*) e1;
    n = (abt*) e2;
    if (m->fre > n->fre) {
        return -1;
    } else if (m->fre < n->fre) {
        return 1;
    } else if (m->let > n->let) {
        return -1;
    } else if (m->let < n->let) {
        return 1;
    }else if(m->let == n->let) return 0;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        double f[26];
        for (int j = 0; j < 26; j++) {
            scanf("%lf", &f[j]);
        }
        char str[200];
        scanf("%s", str);
        int x;
        x = strlen(str);
        abt a[x];
        for (int k = 0; k < x; k++) {
            a[k].let = str[k];
            int num;
            if (a[k].let <= 'z' && a[k].let >= 'a') {
                num = a[k].let - 'a';
            } else {
                num = a[k].let - 'A';
            }
            a[k].fre = f[num];
        }
        qsort(a, x, sizeof(abt), cmp);
        printf("case #%d:\n",i);
        for (int k = 0; k < x; k++) {
            printf("%c", a[k].let);
        }
        printf("\n");
    }
    return 0;
}

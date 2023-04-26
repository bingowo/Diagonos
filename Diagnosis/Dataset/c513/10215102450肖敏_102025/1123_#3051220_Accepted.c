#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct dna {
    char s[21];
    int count;
};
struct dna d[200001], b[200001];

int cmp2(const void *a, const void *b) {
    struct dna *a1 = (struct dna *) a, *b1 = (struct dna *) b;
    return strcmp(a1->s, b1->s);
}

int cmp(const void *a, const void *b) {
    struct dna *a1 = (struct dna *) a, *b1 = (struct dna *) b;
    if (a1->count != b1->count)
        return a1->count - b1->count;
    else
        return strcmp(a1->s, b1->s);
}

int main() {
    int n;
    scanf("%d", &n);
    int a[200001];
    memset(a, 0, sizeof(int) * 200001);
    for (int i = 0; i < n; i++) {
        scanf("%s", d[i].s);
    }
    qsort(d, n, sizeof(d[0]), cmp2);
    int k = 0,j;
    for (int i = 0; i < n;) {
        strcpy(b[k].s, d[i].s);
        b[k].count = 1;
        for (j = i + 1; j < n; j++) {
            if (strcmp(b[k].s, d[j].s) == 0) {
                b[k].count++;
            }
            else break;
        }
        k++;
        i=j;
    }
    qsort(b, k, sizeof(b[0]), cmp);
    for (int i = 0; i < k; i++) {
        printf("%s\n", b[i].s);
    }
    return 0;
}

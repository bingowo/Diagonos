#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    int T;
    scanf("%d", &T);
    int a[1000], b[1000];
    for (int t = 0; t < T; t++) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
        }
        qsort(a, n, sizeof(a[0]), cmp);
        qsort(b, n, sizeof(b[0]), cmp);
        int sum = 0;
        for (int i = 0, j = n - 1; i < n && j >= 0; i++, j--) {
            sum += a[i] * b[j];
        }
        printf("case #%d:\n%d\n", t, sum);
    }
    return 0;
}

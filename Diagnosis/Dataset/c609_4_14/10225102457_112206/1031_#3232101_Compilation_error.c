/*
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000

int a[MAX_N + 1];
int sum[MAX_N*(MAX_N+1)/2 + 1];

int cmp(const void *p1, const void *p2) {
    int *a = (int *)p1;
    int *b = (int *)p2;
    return *a - *b;
}

int main() {
    int t, n, m;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d%d", &n, &m);
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[j]);
        }
        int idx = 1;
        for (int j = 1; j <= n; j++) {
            int s = 0;
            for (int k = j; k <= n; k++) {
                s += a[k];
                sum[idx++] = s;
            }
        }
        qsort(sum+1, n*(n+1)/2, sizeof(int), cmp);
        printf("case #%d:\n", i);
        for (int j = 0; j < m; j++) {
            int l, u;
            scanf("%d%d", &l, &u);
            int ans = 0;
            for (int k = l; k <= u; k++) {
                ans += sum[k];
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
*/
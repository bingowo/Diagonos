#include <stdio.h>
#include <stdlib.h>

#define MAXN 1005
#define MAXM 25

int n, m, t;
int a[MAXN], s[MAXN * (MAXN + 1) / 2];

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    scanf("%d", &t);
    for (int kase = 0; kase < t; kase++) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += a[j];
                s[cnt++] = sum;
            }
        }
        qsort(s, cnt, sizeof(int), cmp);
        printf("case #%d:\n", kase);
        for (int i = 0; i < m; i++) {
            int l, r;
            scanf("%d%d", &l, &r);
            int ans = 0;
            for (int j = l - 1; j < r; j++) {
                ans += s[j];
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}

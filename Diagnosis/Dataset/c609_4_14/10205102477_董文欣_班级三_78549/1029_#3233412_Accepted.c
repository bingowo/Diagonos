#include <stdio.h>
#include <stdlib.h>

int flag[1001] = {0};

int cmp(const void *a, const void *b) {
    int p1 = *(int *)a;
    int p2 = *(int *)b;
    if (flag[p1] == flag[p2]) return p1 - p2;
    return flag[p1] - flag[p2];

}

int main()
{
    int m, n;
    scanf("%d", &m);
    int a[501] = {0}, b[501] = {0};

    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
        flag[a[i]] = i+1;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);

    qsort(b, n, sizeof(b[0]), cmp);
    //输出
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (!flag[b[i]]) {k++;}
    }

    for (int i = k; i < n; i++) printf("%d ",b[i]);
    for (int i = 0; i < k; i++) printf("%d ",b[i]);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct cylinder {
    int r;
    int h;
};
struct cylinder CY[1001];

int cmp(const void *a, const void *b) {
    struct cylinder *a1 = (struct cylinder *) a, *b1 = (struct cylinder *) b;
    return b1->h - a1->h;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &CY[i].r, &CY[i].h);
    }
    qsort(CY, n, sizeof(CY[0]), cmp);
    int RM = CY[0].r, k = 0;
    for (int j = 1; j < n; j++) {
        if (CY[j].r > RM) {
            RM = CY[j].r;
            k = j;
        } else
            continue;
    }


    if (k >= m) {
        CY[m - 1].h = CY[k].h;
        CY[m - 1].r = CY[k].r;
    }
    long long int sum = CY[k].r * CY[k].r;

    for (int x = 0; x < m; x++) {
        sum += 2 * CY[x].h * CY[x].r;
    }

    printf("%lld", sum);
    return 0;
}

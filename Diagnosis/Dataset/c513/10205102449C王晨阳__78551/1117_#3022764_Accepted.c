#include <stdio.h>
#include <stdlib.h>

long long x0, y0;

typedef struct {
    long long x, y, distance;
} point;

long long ABS(long long a) {
    return a > 0 ? a : -a;
}

long long max(long long a, long long b) {
    return a > b ? a : b;
}

void calculate(point *a) {
    a->distance = max(ABS(a->x - x0), ABS(a->y - y0));
}

int cmp(const void *a, const void *b) {
    point *a1 = (point *) a, *b1 = (point *) b;
    if (a1->distance != b1->distance) {
        if (a1->distance > b1->distance)
            return 1;
        return -1;
    } else {
        if (a1->x != b1->x) {
            if (a1->x > b1->x)
                return 1;
            return -1;
        } else {
            if (a1->y > b1->y)
                return 1;
            return -1;
        }
    }
}

int main() {
    int n;
    scanf("%lld %lld %d", &x0, &y0, &n);
    point *p = (point *) malloc(sizeof(point) * n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &p[i].x, &p[i].y);
        calculate(&p[i]);
    }
    qsort(p, n, sizeof(point), cmp);
    printf("%lld\n%lld %lld\n", p[0].distance, p[0].x, p[0].y);
    return 0;
}

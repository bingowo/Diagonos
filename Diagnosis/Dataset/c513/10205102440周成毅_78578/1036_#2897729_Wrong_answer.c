#include <stdio.h>
#include <stdlib.h>

typedef struct POINT {
    long long x;
    long long y;
} point;

unsigned long long ABS(long long a) {
    return a > 0 ? a : -a;
}

int cmp(const void *a, const void *b) {
    point *a1 = (point *) a;
    point *b1 = (point *) b;
    if ((ABS(a1->x) + ABS(a1->y)) != (ABS(b1->x) + ABS(b1->y))) {
        if ((ABS(a1->x) + ABS(a1->y)) > (ABS(b1->x) + ABS(b1->y)))
            return -1;
        return 1;
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

int judge(point a, point b) {
    if ((ABS(a.x - b.x) + ABS(a.y + b.y)) % 2 != 0) {
        return 1;
    } else {
        if ((ABS(a.x - b.x) + ABS(a.y + b.y)) == 0)
            return 1;
        else
            return 0;
    }
}

long long power(long long a, long long b) {
    if (b == 0)
        return 1;
    else
        return a * power(a, b - 1);
}

long long find(long long num) {
    if (num == 0)
        return 0;
    int tag = 0;
    if (num % 2 != 0)
        tag = 1;
    long long bit = 0;
    while (!(num >= power(2, bit) && num <= power(2, bit + 1)))
        bit++;
    return bit + tag;
}

int main() {
    int n;
    scanf("%d", &n);
    point list[101];
    for (int i = 0; i < n; i++)
        scanf("%lld %lld", &list[i].x, &list[i].y);
    qsort(list, n, sizeof(point), cmp);
    unsigned long long steps = 0;
    unsigned long long dx, dy;
    dx = ABS(list[0].x - list[1].x);
    dy = ABS((list[0].y - list[1].y));
    unsigned long long distance = dx + dy;
    if (dx > distance)
        printf("18446744073709551616\n");
    else
        printf("%u\n", distance);
    for (int i = 0; i < n - 1; i++) {
        if (list[i].x == list[i + 1].x && list[i].y == list[i + 1].y)
            continue;
        dx = ABS(list[i].x - list[i + 1].x);
        dy = ABS(list[i].y - list[i + 1].y);
        distance = dx + dy;
        if (dx % 2 != dy % 2) {
            if (distance > (1ULL << 63)) {
                steps += 64;
                continue;
            }
            for (int j = 0; j < 64; j++) {
                if ((distance < (1ULL << (j + 1))) && (distance >= (1ULL << j))) {
                    steps += (j + distance % 2);
                    break;
                }
            }
        } else
            break;
    }
    printf("%lld\n", steps);
    return 0;
}
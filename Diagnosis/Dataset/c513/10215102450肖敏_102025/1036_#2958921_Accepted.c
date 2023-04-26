#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct st {
    long long int x;
    long long int y;
    unsigned long long int d;
};

int cmp(const void *a, const void *b) {
    struct st *a1 = (struct st *) a;
    struct st *b1 = (struct st *) b;
    if (a1->d != b1->d)return a1->d < b1->d;
    else if (a1->x != b1->x)return a1->x > b1->x;
    else return a1->y > b1->y;
}

long long confer(unsigned long long x1, unsigned long long y1) {
    int m = 0;
    while (x1 != 0 || y1 != 0) {
        if (x1 % 2 == 1 && y1 % 2 == 0) {
            if (x1 == 1 && y1 == 0)x1--;
            else if ((x1 + 1) / 2 % 2 != y1 / 2 % 2)x1++;
            else x1--;
            x1 /= 2;
            y1 /= 2;
            m++;
        } else if (x1 % 2 == 0 && y1 % 2 == 1) {
            if (x1 == 0 && y1 == 1)y1--;
            else if ((y1 + 1) / 2 % 2 != x1 / 2 % 2)y1++;
            else y1--;
            x1 /= 2;
            y1 /= 2;
            m++;
        } else break;
    }
    return m;
}

int main() {
    int n, t, i;
    scanf("%d", &n);
    struct st k[n];
    for (t = 0; t < n; t++) {
        scanf("%lld %lld", &k[t].x, &k[t].y);
        k[t].d = llabs(k[t].x) + llabs(k[t].y);
    }
    qsort(k, n, sizeof(k[0]), cmp);
    unsigned long long d1 = llabs(k[0].x - k[1].x);
    unsigned long long d2 = llabs(k[0].y - k[1].y);
    if (d1 + d2 == 0 && d1 > 0) printf("18446744073709551616\n");
    else printf("%llu\n", d1 + d2);
    unsigned long long x1, y1, step = 0;
    long long confer(unsigned long long x1, unsigned long long y1);
    int m = 1;
    i = 0;
    if (k[i].x == k[i + 1].x && k[i].y == k[i + 1].y)i++;
    for (; i < n - 1 && m != 0; i++) {
        x1 = llabs(k[i].x - k[i + 1].x);
        y1 = llabs(k[i].y - k[i + 1].y);
        m = confer(x1, y1);
        step += m;
    }
    printf("%lld", step);
}

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct R{
    double r, theta;
};
int doublecmp(double a, double b) {
    if(a == b) return 0;
    if(a < b) return -1;
    else return 1;
}
int cmp(const void *a, const void *b) {
    const struct R *r1 = a, *r2 = b;
    int c = doublecmp(r1->theta, r2->theta);
    if(c == 0) {
        return -doublecmp(r1->r, r2->r);
    } else {
        return c;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; ++i) {
        int n;
        scanf("%d", &n);
        struct R v[10000];
        struct R *p = v;
        for(int i = 0; i < n; i++) {
            double a, b;
            scanf("%lf %lf", &a, &b);
            double theta = atan2(b,a);
            p->r = hypot(a,b);
            p->theta = theta < 0? theta + atan(1.0) * 8: theta;
            p++;
        }
        qsort(v, n, sizeof(struct R), cmp);
        printf("case #%d:\n", i);
        for(int i = 0; i < n; i++) {
            printf("(%.4lf,%.4lf)\n", v[i].r, v[i].theta);
        }
    }

    return 0;
}

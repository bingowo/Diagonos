#include <stdio.h>

int main() {
    int n, i;
    double d, k, s, tmp;
    double max = -1;
    scanf("%lf%d", &d, &n);
    for (i = 0; i < n; ++i) {
        scanf("%lf%lf", &k, &s);
        tmp = (d-k) / s;
        if (tmp > max)
            max = tmp;
    }
    printf("%.6f", d / max);
}
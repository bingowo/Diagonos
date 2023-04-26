#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double length;
    double theta;
} polar_crd;

int cmp(const void* p1, const void* p2) {
    polar_crd points_a = *(polar_crd*)p1, points_b = *(polar_crd*)p2;
    if (fabs(points_a.theta - points_b.theta) < 1e-7)
        return (points_a.length - points_b.length < 0 ? 1 : -1);
    return (points_a.theta - points_b.theta < 0 ? -1 : 1);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i != T; ++i) {
        polar_crd arr_pts[1000];
        int n;
        scanf("%d", &n);
        for (int j = 0; j != n; ++j) {
            double x, y;
            scanf("%lf%lf", &x, &y);
            arr_pts[j].length = sqrt(x * x + y * y);
            arr_pts[j].theta = atan(fabs(y / x));
            if (x > 0 && y < 0)
                arr_pts[j].theta = 2 * acos(-1.0) - arr_pts[j].theta;
            else if (x <= 0 && y < 0)
                arr_pts[j].theta += acos(-1.0);
            else if (x < 0 && y >= 0)
                arr_pts[j].theta = acos(-1.0) - arr_pts[j].theta;
        }
        qsort(arr_pts, n, sizeof(polar_crd), cmp);
        printf("case #%d:\n", i);
        for (int j = 0; j != n; ++j)
            printf("(%.4f,%.4f)\n", arr_pts[j].length, arr_pts[j].theta);
    }
    return 0;
}
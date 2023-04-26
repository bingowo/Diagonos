#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define  M_PI 2*3.1415926

struct polar {
    double m;
    double angle;
};

int cmp(const void *a, const void *b) {
    struct polar *aa = (struct polar *) a;
    struct polar *bb = (struct polar *) b;
    if (aa->angle > bb->angle)
        return 1;
    else if (aa->angle < bb->angle)
        return -1;
    else {
        if (aa->m > bb->m)
            return -1;
        return 1;
    }
}

int main() {


    struct polar POLAR[1002];
    int T, i;
    scanf("%d", &T);
    for (i = 0; i < T; i++) {
        int N, j;
        scanf("%d", &N);
        for (j = 0; j < N; j++) {
            double x, y;
            scanf("%lf %lf", &x, &y);
            POLAR[j].m = sqrt(x * x + y * y);
            if (POLAR[j].m == 0)
                POLAR[j].angle = 0.0;
            else {
                if (atan2(y, x) < 0)
                    POLAR[j].angle = atan2(y, x) + M_PI;
                else
                    POLAR[j].angle = atan2(y, x);
            }
        }

        qsort(POLAR, N, sizeof(POLAR[0]), cmp);
        printf("case #%d:\n", i);
        for (int k = 0; k < N; k++)
            printf("(%.4f,%.4f)\n", POLAR[k].m, POLAR[k].angle);
    }
    return 0;
}

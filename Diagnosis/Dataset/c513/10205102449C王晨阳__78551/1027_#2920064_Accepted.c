#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>

#define PI 3.1415926

double length(double a, double b);

double angle(double a, double b);

int cmp(const void *a, const void *b);

int main() {
    int T, N;
    double a, b;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        double **frame;
        double *fr;
        scanf("%d", &N);
        frame = (double **) malloc(sizeof(double *) * N);
        printf("case #%d:\n", i);
        for (int j = 0; j < N; j++) {
            fr = (double *) malloc(sizeof(double) * 2);
            frame[j] = fr;
        }
        for (int m = 0; m < N; m++) {
            scanf("%lf %lf", &a, &b);
            frame[m][0] = length(a, b);
            frame[m][1] = angle(a, b);
        }
        qsort(frame, N, sizeof(frame[0]), cmp);
        for (int k = 0; k < N; k++)
            printf("(%.4lf,%.4lf)\n", frame[k][0], frame[k][1]);
        free(frame);
    }
    return 0;
}

double length(double a, double b) {
    double le;
    le = pow((pow(a, 2.0) + pow(b, 2.0)), 0.5);
    return le;
}

double angle(double a, double b) {
    double an;
    an = atan2(b, a);
    if (a == 0 && b > 0) {
        return 1.570796;
    } else if (a == 0 && b < 0) {
        return 4.712389;
    } else if (a > 0 && b > 0)
        return an;
    else if (a > 0 && b < 0)
        return an + 2 * PI;
    else if (a < 0 && b > 0)
        return an;
    else if (a < 0 && b < 0)
        return an + 2 * PI;
    else if (a > 0 && b == 0)
        return 0.00000;
    else if (a < 0 && b == 0)
        return an;
}

int cmp(const void *a, const void *b) {
    double *ap = *(double **) a;
    double *bp = *(double **) b;

    if (ap[1] != bp[1]) {
        if (ap[1] > bp[1])
            return 1;
        else
            return -1;
    } else if (ap[1] == bp[1]) {
        if (ap[0] > bp[0])
            return -1;
        else
            return 1;
    }
}
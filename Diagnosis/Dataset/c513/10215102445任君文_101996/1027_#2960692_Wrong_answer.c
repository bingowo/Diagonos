#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include<ctype.h>
#define M 1000
void swap(double* x, double* y)
{
    double temp = *x;
    *x = *y;
    *y = temp;
}
int main()
{
    int T, N;
    int i, j, k;
    double x[M] = { 0 };
    double y[M] = { 0 };
    double p[M] = { 0 };
    double r[M] = { 0 };
    scanf("%d", &T);
    for (i = 0; i < T; i++)
    {
        scanf("%d", &N);
        for (j = 0; j < N; j++)
        {
            scanf("%lf%lf", &x[j], &y[j]);
            p[j] = sqrt(pow(x[j], 2) + pow(y[j], 2));
            r[j] = atan(y[j] / x[j]);
        }
        for (j = 0; j < N-1; j++)
        {
            for (k = 0; k < N - 1 - j; k++)
            {
                if (r[k] > r[k + 1])
                {
                    swap(&r[k], &r[k + 1]);
                    swap(&p[k], &p[k + 1]);
                }
                else if (r[k] == r[k + 1])
                {
                    if (p[k] < p[k + 1])
                    {
                        swap(&r[k], &r[k + 1]);
                        swap(&p[k], &p[k + 1]);
                    }
                }
            }
        }
        printf("case #%d:\n", i);
        for (j = 0; j < N; j++)
        {
            printf("(%.4lf,%.4lf)\n", p[j], r[j]);
        }
    }
    return 0;
}
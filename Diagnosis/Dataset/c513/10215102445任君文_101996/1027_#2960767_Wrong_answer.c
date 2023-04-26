#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include<ctype.h>
#define M 1000
#define pi 3.1415926535898
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
            if (x[j] < 0)
            {
                if (y[j] < 0)
                {
                    y[j] = -y[j];
                    x[j] = -x[j];
                    r[j] = pi + atan(y[j] / x[j]);
                }
                else if (y[j] > 0)
                {
                    y[j] = -y[j];
                    x[j] = -x[j];
                    r[j] = (pi/2.0) + atan(y[j] / x[j]);
                }
                else
                {
                    r[j] = 0;
                }
            }
            else if (x[j] > 0)
            {
                if (y[j] > 0)
                {
                    r[j] =atan(y[j] / x[j]);
                }
                else if (y[j] < 0)
                {
                    y[j] = -y[j];
                    r[j] = (pi * 3.0) / 2 + atan(y[j] / x[j]);
                }
                else
                {
                    r[j] = 0;
                }
            }
            else
            {
                if (y[j] > 0)
                {
                    r[j] = pi / 2.0;
                }  
                else if (y[j] < 0)
                {
                    r[j] = (pi*3.0)/2;
                }
                else
                {
                    r[j] = 0;
                }
            }
            
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
            printf("(%.4lf,%4lf)\n", p[j], r[j]);
        }
    }
    return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include <math.h>
typedef struct add
{
    double x;
    double y;
    double angle;
    double l;
}ad;
int cmp(const void* p1, const void* p2)
{
    ad* p_1 = (ad*)p1;
    ad* p_2 = (ad*)p2;
    double a = p_2->angle - p_1->angle;
    if (a > 0)return 0;
    else if (a == 0)return (p_1->l > p_2->l) ? 0 : 1;
    else return 1;
}
double cal(double x, double y)
{
    double n = x * x + y * y;
    double res = 3;
    double res_;
    while (fabs(res_-res) > 0.000000001)
    {
        res_ = res;
        res = n /(2* res) + res / 2;
    
    }
    return res;
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int z = 0;z < t;z++)
    {
        int n;
        scanf("%d", &n);
        int q;
        struct add p[1001];
        for (q = 0;q < n;q++)
        {
            scanf("%lf%lf", &p[q].x, &p[q].y);
            p[q].l = cal(p[q].x, p[q].y);
            if (fabs(p[q].x) < 0.0000001)
            {
                if (p[q].y > 0) p[q].angle = 3.1415926 / 2;
                else p[q].angle = 3.1415926 * 3 / 2;
            }
            else
            {
                p[q].angle = atan(p[q].y / p[q].x);
                if ((fabs(p[q].y)<  0.000000001) && p[q].x < 0)p[q].angle = 3.1415926;
                else if (p[q].x > 0)
                {
                    if (p[q].y < 0) p[q].angle = 2 * 3.1415926 + p[q].angle;
                }
                else
                {
                       p[q].angle = 3.1415926 + p[q].angle;
                }
            }
        }
        qsort(p, n, sizeof(ad), cmp);
        printf("case #%d:\n", z);
        for (int i = 0;i < n;i++)
        {
            printf("(%.4lf,%.4lf)\n", p[i].l, p[i].angle);
        }
    }
    return 0;
}


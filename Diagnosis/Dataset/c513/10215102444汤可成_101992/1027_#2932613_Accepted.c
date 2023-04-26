#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point
{
    double x;
    double y;
}point;

int cmp(const void* a, const void* b)
{
    point* pa = (point*)a;
    point* pb = (point*)b;
    if(pa->y > pb->y) return 1;
    else if(pa->y < pb->y) return -1;
    else
    {
        if(pa->x > pb->x) return -1;
        else return 1;
    }
}

int main()
{
    int T = 0;
    int i = 0;
    scanf("%d", &T);
    for(i = 0; i<T; i++)
    {
        point p[1001] = {0};
        int n = 0;
        scanf("%d", &n);
        printf("case #%d:\n", i);
        int j = 0;
        for(j = 0; j<n; j++)
        {
            double x = 0, y = 0;
            scanf("%lf %lf", &x, &y);
            p[j].y = atan2(y,x);
            if(x<0 && y<0) p[j].y += 3.1415926*2;
            else if(x>=0 && y<0) p[j].y += 3.1415926*2;
            p[j].x = sqrt(x*x+ y*y);
        }
        qsort(p, n, sizeof(p[0]), cmp);
        for(j = 0; j<n; j++)
        {
            printf("(%.4lf,%.4lf)\n", p[j].x, p[j].y);
        }
    }
    return 0;
}

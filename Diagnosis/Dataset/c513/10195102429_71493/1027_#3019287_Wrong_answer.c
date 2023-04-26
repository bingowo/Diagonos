#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct point
{
    double x;
    double y;
    double p;
    double angle;
};

int cmp(const void *d1,const void *d2)
{
    struct point a,b;
    a=*((struct point *)d1);
    b=*((struct point *)d2);
    if (a.angle==b.angle){
        if(a.p>b.p)
            return -1;
        else return 1;
    }
    else if(a.angle>b.angle)
        return 1;
    else return -1;
    }



int main()
{
    int t;
    scanf("%d",&t);
    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d",&n);
        struct point a[1000];
        for (int j = 0; j < n; j++)
        {
            scanf("%lf%lf",&a[j].x,&a[j].y);
            a[j].p = sqrt(a[j].x*a[j].x + a[j].y*a[j].y);
            if (a[j].y >= 0) a[j].angle = acos(a[j].x / a[j].p);
            else a[j].angle = 2 * acos(-1) - acos(a[j].x / a[j].p);
        }
        qsort(a,n,sizeof(a[0]), cmp);
        printf("case #%d:\n",i);
        for (int j = 0; j < n; j++)
            printf("(%.4lf,%.4lf)\n", a[j].p, a[j].angle);
    }
}

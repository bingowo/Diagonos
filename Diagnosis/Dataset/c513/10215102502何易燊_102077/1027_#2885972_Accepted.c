#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {double x,y; double dis; double angle;} point;

double dis(double a,double b)
{
    return sqrt(a*a+b*b);
}

int cmp(const void* a,const void* b)
{
    point* c = (point*)a; point* d = (point*)b;
    if (c->angle!=d->angle) return (c->angle>=d->angle)? 1:-1;
    else return (d->dis>=c->dis)? 1: -1;
}

main()
{
    int T;
    scanf("%d",&T);
    point a[1001];
    for (int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        for (int j=0;j<n;j++)
        {
            scanf("%lf %lf",&a[j].x,&a[j].y);
            a[j].dis = dis(a[j].x,a[j].y);
            //a[i].angle = (atan2(a[i].y,a[i].x)>=0)? atan2(a[i].y,a[i].x): atan2(a[i].y,a[i].x)+2*3.1415926;
            a[j].angle = atan2(a[j].y,a[j].x);
            if (a[j].angle<0) a[j].angle += 2*3.1415926;
        }
        qsort(a,n,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        for (int j=0;j<n;j++) printf("(%.4lf,%.4lf)\n",a[j].dis,a[j].angle); 
    }
    return 0;
}
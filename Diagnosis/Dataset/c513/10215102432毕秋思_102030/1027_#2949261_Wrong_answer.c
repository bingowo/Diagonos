#include<stdio.h>
#include<math.h>
#define PI 3.141592653589793

struct Point
{
    double x;
    double y;
    double ang;
    double r;
}points[1000];

int cmp(const void *q1,const void *q2)
{
    struct Point *p1=(struct Point*)q1;
    struct Point *p2=(struct Point*)q2;
    if(p1->ang>p2->ang) return 1;
    else if(p1->ang<p2->ang) return -1;
    else if(p1->ang==p2->ang)
    {
        if(p1->r<p2->r) return 1;
        else return -1;
    }
}

double my_atan(double x,double y)
{
    if(x>0&&y>0) return atan(y/x);
    if(x<0&&y>0) return atan(fabs(y/x))+PI/2.0;
    if(x<0&&y<0) return atan(fabs(y/x))+PI;
    if(x>0&&y<0) return atan(fabs(y/x))+PI*3.0/2.0;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        int n=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf",&points[i].x,&points[i].y);
            points[i].ang=fabs(my_atan(points[i].x,points[i].y));
            points[i].r=sqrt(points[i].x*points[i].x+points[i].y*points[i].y);
        }

        qsort(points,n,sizeof(struct Point),cmp);

        printf("case #%d:\n",t);
        for(int i=0;i<n;i++)
            printf("(%.4f,%.4f)\n",points[i].r,points[i].ang);
    }
    return 0;
}

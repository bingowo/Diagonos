#include<stdio.h>
#include<math.h>

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
            points[i].ang=fabs(atan2(points[i].y/points[i].x));
            points[i].r=sqrt(points[i].x*points[i].x+points[i].y*points[i].y);
        }

        qsort(points,n,sizeof(struct Point),cmp);

        printf("case #%d:\n",t);
        for(int i=0;i<n;i++)
            printf("(%.4f,%.4f)\n",points[i].r,points[i].ang);
    }
    return 0;
}

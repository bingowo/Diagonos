#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct
{
    double x;
    double y;
    double distance;
    double angle;
}Point;
int cmp(const void*a,const void*b)
{
    Point*st1,*st2;
    st1 = (Point*)a,st2 = (Point*)b;
    if(st1->angle - st2->angle >= 0.0001)
        return 1;
    else if(st2->angle - st1->distance >= 0.0001)
        return -1;
    else
    {
        if(st1->distance - st2->distance > 0.0001)
            return -1;
        else if(st2->distance - st1->distance > 0.0001)
            return 1;

    }
}
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        int N,j;
        scanf("%d",&N);
        Point dot[N];
        for(j = 0;j < N;j++)
        {
            scanf("%lf %lf",&dot[j].x,&dot[j].y);
            dot[j].distance = sqrt(dot[j].x*dot[j].x+dot[j].y*dot[j].y);
            dot[j].angle = atan(dot[j].y/dot[j].x);
        }
        qsort(dot,N,sizeof(dot[0]),cmp);
        printf("case #%d:\n",i);
        for(j = 0;j < N;j++)
            printf("(%.4lf,%.4lf)\n",dot[j].distance,dot[j].angle);

    }
    return 0;
}
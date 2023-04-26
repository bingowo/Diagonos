#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.141592
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
    if(fabs(st1->angle - st2->angle) < 0.0001)
        return 0;
    else if(st1->angle - st2->angle > 0.0001)
        return 1;
    else
        return -1;
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
            if(dot[j].x == 0)
            {
                if(dot[j].y > 0)
                    dot[j].angle = PI/2;
                else if(dot[j].y < 0)
                    dot[j].angle = 3*PI/2;
                else
                    dot[j].angle = 0;
            }
            else
            {
                dot[j].angle = atan(dot[j].y/dot[j].x);
                if(dot[j].x < 0 && dot[j].y > 0)
                    dot[j].angle = PI + dot[j].angle;
                else if(dot[j].x < 0 && dot[j].y < 0)
                    dot[j].angle = dot[j].angle + PI;
                else if(dot[j].x > 0&&dot[j].y < 0)
                    dot[j].angle = 2*PI + dot[j].angle;
                else if(dot[j].y == 0)
                {
                    if(dot[j].x < 0)
                        dot[j].angle = PI;
                    else
                        dot[j].angle = 0;
                }
            }

        }
        qsort(dot,N,sizeof(dot[0]),cmp);
        printf("case #%d:\n",i);
        for(j = 0;j < N;j++)
            printf("(%.4lf,%.4lf)\n",dot[j].distance,dot[j].angle);

    }
    return 0;
}

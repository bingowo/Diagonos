#include<stdio.h>
#include<math.h>
#include<stdlib.h>

struct position
{
    double x,y;
};
int cmp(const void* a,const void* b);
int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        struct position point[n];
        for (int j=0;j<n;j++)
        {
            scanf("%lf%lf",&point[j].x,&point[j].y);
            double arc=fabs(atan2(point[j].y,point[j].x));
            if (point[j].y<0) arc+=3.1415926;
            double p=sqrt(point[j].x*point[j].x+point[j].y*point[j].y);
            point[j].x=p,point[j].y=arc;
        }
        struct position temp;
        for (int j=0;j<n-1;j++)
        {
            for (int k=n-1;k>j;k--)
            {
                if (point[k].y<point[k-1].y)
                {
                    temp = point[k];
                    point[k] = point[k-1];
                    point[k-1] = temp;
                }
            }
        }
        printf("case #%d:\n",i);
        for (int j=0;j<n;j++)
        {
            printf("(%.4llf,%.4llf)\n",point[j].x,point[j].y);
        }
    }
}

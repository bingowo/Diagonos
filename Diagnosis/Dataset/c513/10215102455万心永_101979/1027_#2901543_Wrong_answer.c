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
            double z=pow(point[j].x,2)+pow(point[j].y,2),arc=0,p=sqrt(z);
            if ((point[j].x>=0&&point[j].y>=0))
                arc=(atan2(point[j].y,point[j].x));
            else if (point[j].x<0&&point[j].y>=0)
                arc=(acos(point[j].x/p));
            else if (point[j].x<=0&&point[j].y<0)
                arc=3.14159265358979-asin(point[j].y/p);
            else if(point[j].x>0&&point[j].y<0)
            {   
                point[j].y=-point[j].y;
                arc=6.28318530717958-(atan2(point[j].y,point[j].x));
            }
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
                else if ((point[k].y-point[k-1].y)<0.0001)
                {
                    if (point[k].x>point[k-1].x)
                    {
                        temp = point[k];
                        point[k] = point[k-1];
                        point[k-1] = temp;
                    }
                }
            }
        }
        printf("case #%d:\n",i);
        for (int j=0;j<n;j++)
        {
            printf("(%.4lf,%.4lf)\n",point[j].x,point[j].y);
        }
    }
}

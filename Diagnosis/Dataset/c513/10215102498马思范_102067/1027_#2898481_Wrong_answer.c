#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926535
typedef struct
{
    double x;
    double y;
}coord;
double getp(double a,double b)
{
    return pow(pow(a,2.0)+ pow(b,2.0),0.5);
}
double getj(double a,double b)
{
    if(a>0&&b>0)
        return atan(b/a);
    else if(a<0&&b>0)
        return atan(b/a)+PI;
    else if(a<0&&b<0)
        return atan(b/a)+PI;
    else if(a>0&&b<0)
        return atan(b/a)+2*PI;
    else if(b==0)
        return atan(b/a);
    else if(a==0&&b>0)
        return PI/2;
    else if(a==0&&b<0)
        return 1.5*PI;
}
int cmp(const void *a,const void *b)
{
    coord x=*(coord *)a;
    coord y=*(coord *)b;
    if (fabs(getj(x.x,x.y)-getj(y.x,y.y))<1e-8)
    {
        if(getp(y.x,y.y)>getp(x.x,x.y))
            return 1;
        else return -1;
    }
    else
    {
        if(getj(x.x,x.y)<getj(y.x,y.y))
            return -1;
        else return 1;
    }
}
int main()
{
    int t;
    int n;
    coord a[1001];
    scanf("%d",&t);
    for(int m=0;m<t;m++)
    {
        scanf("%d",&n);
        for(int r=0;r<n;r++)
        {
            scanf("%lf%lf",&a[r].x,&a[r].y);
        }
        qsort(a,n,sizeof(a[0]),cmp);
        printf("case #%d:\n",m);
        for(int f=0;f<n;f++)
            printf("(%.4f,%.4f)\n", getp(a[f].x,a[f].y), getj(a[f].x,a[f].y));
    }
    return 0;
}
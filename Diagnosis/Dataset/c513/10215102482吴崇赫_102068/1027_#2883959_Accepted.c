#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define PI 3.1415926
#define N 1005

typedef struct
{
    double r;
    double angle;
}polar;

typedef struct
{
    double x;
    double y;
}point;

int cmp(const void* a,const void* b)
{
    polar* pa=(polar*)a;
    polar* pb=(polar*)b;
    if(pa->angle!=pb->angle)return pa->angle>pb->angle?1:-1;
    else if(pa->r!=pb->r)return pa->r<pb->r?1:-1;
    else return 0;
}

double getR(point a)
{
    double ret=sqrt(a.x*a.x+a.y*a.y);
    return ret;
}

double getangle(point a)
{
    double tmp=a.y/a.x;
    if(a.y>=0&&a.x>0)return atan(tmp);
    if(a.x<0&&a.y>=0)return atan(tmp)+PI;
    if(a.x<0&&a.y<0)return atan(tmp)+PI;
    if(a.x>0&&a.y<0)return atan(tmp)+2*PI;
    if(a.x==0&&a.y>0)return PI/2;
    if(a.x==0&&a.y<0)return PI*3/2;
}

int main()
{
    int T,x=0;
    scanf("%d\n",&T);
    while(x<T){
        point p[N];polar a[N];
        for(int i=0;i<N;++i){
            p[i].x=p[i].y=0.00;
            a[i].angle=a[i].r=0.00;
        }
        int n;scanf("%d\n",&n);
        for(int i=0;i<n;++i){
            scanf("%lf %lf",&p[i].x,&p[i].y);
            a[i].angle=getangle(p[i]);
            a[i].r=getR(p[i]);
        }
        qsort(a,n,sizeof(a[0]),cmp);
        printf("case #%d:\n",x++);
        for(int i=0;i<n;++i){
            printf("(%.4lf,%.4lf)\n",a[i].r,a[i].angle);
        }

    }
    return 0;
}

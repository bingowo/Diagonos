#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct point{
double x;double y;double angle;double length;};

double length(double x,double y)
{
    double temp=pow(x,2)+pow(y,2);
    temp=sqrt(temp);
    return temp;
}

double angle(double x,double y)
{
    if(x==0&&y>0)
    {
        return acos(0);
    }
    else if(x==0&&y<0)
    {
        return 3*acos(0);
    }
    double temp=y/x;
    if(x>0&&y>=0)
    {
        return atan(temp);
    }
    else if(x>0&&y<0)
    {
        return 4*acos(0)+atan(temp);
    }
    else
    {
       return 2*acos(0)+atan(temp);
    }
}

int cmp(const void* a,const void* b)
{
    struct point* p1=(struct point*)a;
    struct point* p2=(struct point*)b;
    if(p1->angle<p2->angle)
    {
        return -1;
    }
    else if(p1->angle>p2->angle)
    {
        return 1;
    }
    else{
        if(p1->length>p2->length)
        {
            return -1;
        }
        else{return 1;}
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int tag=0;tag<T;tag++)
    {
        printf("case #%d:\n",tag);
        int N;
        scanf("%d",&N);
        struct point point[N];
        for(int i=0;i<N;i++)
        {
            scanf("%lf %lf",&point[i].x,&point[i].y);
            point[i].length=length(point[i].x,point[i].y);
            point[i].angle=angle(point[i].x,point[i].y);
        }
        qsort(point,N,sizeof(point[0]),cmp);
        for(int i=0;i<N;i++)
        {
            printf("(%.4lf,%.4lf)\n",point[i].length,point[i].angle);
        }


    }
    return 0;

}

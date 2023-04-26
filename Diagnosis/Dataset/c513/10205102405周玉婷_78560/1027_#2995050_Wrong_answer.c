#include <stdio.h>
#include <math.h>
#include <stdlib.h>
const double pi=3.14159262;
const double ep=1e-8;

typedef struct{
    double x;
    double y;
    double r;
    double th;
} point ;

int cmp(const void *a,const void *b)
{
    point pa=*(point *)a;
    point pb=*(point *)b;
    if(fabs(pa.th-pb.th)<ep) 
    {
        return pa.r<pb.r?1:-1;
    }
    else 
    {
        if(pa.th<pb.th) return 1;
        else return -1;
    }
}


int main()
{
    int t;
    scanf("%d",&t);

    for(int j=0; j<t; j++)
    {
        int n;
        scanf("%d",&n);

        point *p=(point *)malloc(sizeof(point)*n);
        for(int i=0; i<n; i++)//将数输入到空间
        {
            scanf("%lf %lf",&p[i].x,&p[i].y);
            p[i].r=sqrt(p[i].x*p[i].x+p[i].y*p[i].y);
            p[i].th=atan2(p[i].y,p[i].x);
            if(p[i].th<0) p[i].th=p[i].th+2*pi;
        }

        qsort(p,n,sizeof(point),cmp);
        printf("case #%d:\n",j);
        for(int i=0; i<n; i++)
        {
            printf("(%.4f,%.4f)\n",p[i].r,p[i].th);
        }
    }
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define PI acos(-1)
typedef struct 
{
    double p;
    double tan;
}POINT;

int cmp(const void* a, const void* b)
{
    POINT a0=*(POINT*)a;POINT b0=*(POINT*)b;
    if(fabs(a0.tan-b0.tan)<=10e-8) return a0.p>b0.p ? -1:1;
    else return a0.tan>b0.tan ? 1:-1;
}

int main()
{
    int T,t=0;
    scanf("%d",&T);
    while (T--)
    {
        int i,num;
        scanf("%d",&num);
        POINT point[num];
        for(i=0;i<num;i++)
        {
            double x,y;
            scanf("%lf %lf",&x,&y);
            point[i].p=x*x+y*y;
            if(x==0 && y>0) point[i].tan=PI/2;
            else if(x==0 && y<0) point[i].tan=3*PI/2;
            else if(x>0 && y==0) point[i].tan=0;
            else if(x<0 && y==0) point[i].tan=PI;
            else if(x>0 && y>0) point[i].tan=atan(y/x);
            else if(x<0 && y>0) point[i].tan=atan(y/x)+PI;
            else if(x<0 && y<0) point[i].tan=atan(y/x)+PI;
            else if(x>0 && y<0) point[i].tan=atan(y/x)+2*PI;
        }
        qsort(point,num,sizeof(point[0]),cmp);
        printf("case #%d:\n",t);
        for(i=0;i<num;i++)
        {
            printf("(%.4lf,%.4lf)\n",sqrt(point[i].p),point[i].tan);
        }
        t++;
    }
    return 0;
}
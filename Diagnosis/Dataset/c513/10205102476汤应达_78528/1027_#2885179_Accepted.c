#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define pi 3.1415926
typedef struct dot
{
    double angle,rou,x,y;
}dot;

int cmp(const void*a,const void*b)
{
    dot a0=*(dot*)a,b0=*(dot*)b;
    if(a0.angle>b0.angle) return 1;
    else if(a0.angle<b0.angle) return -1;
    else
    {
        if(a0.rou<b0.rou) return 1;
        else return -1;
    }
}

int main()
{
    int T;scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n;scanf("%d",&n);
        dot*p=(dot*)malloc(sizeof(dot)*n);
        for(int t=0;t<n;t++)
        {
            double x,y;
            scanf("%lf %lf",&x,&y);
            p[t].x=x,p[t].y=y;
            p[t].rou=sqrt(x*x+y*y);
            if(x==0)
            {
                if(y>0) p[t].angle=pi/2;
                else if(y<0) p[t].angle=3*pi/2;
                else p[t].angle=0;
            }
            else if(y==0)
            {
                if(x>0) p[t].angle=0;
                else p[t].angle=pi;
            }
            else if(atan(y/x)<0)
            {
                if(y>0) p[t].angle=pi+atan(y/x);
                else p[t].angle=2*pi+atan(y/x);
            }
            else
            {
                if(y>0) p[t].angle=atan(y/x);
                else p[t].angle=pi+atan(y/x);
            }
        }
        qsort(p,n,sizeof(p[0]),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<n;j++) printf("(%.4lf,%.4lf)\n",p[j].rou,p[j].angle);
    }

    return 0;
}
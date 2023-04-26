#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct jizuobiao
{
    double r;
    double angle;
};

int cmp(const void*a,const void*b)
{
    struct jizuobiao* ap=(struct jizuobiao*)a;
    struct jizuobiao* bp=(struct jizuobiao*)b;
    if(ap->angle!=bp->angle)
    {
        if(ap->angle>bp->angle)
            return 1;
        else
            return -1;
    }
    else
    {
        if(ap->r>bp->r)
            return -1;
        else
            return 1;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    int i;
    for(i=0;i<T;i++)
    {
        int N,j;//µãµÄ¸öÊý
        scanf("%d",&N);
        struct jizuobiao a[1000];
        for(j=0;j<N;j++)
        {
            a[j].r=0.0000;a[j].angle=0.0000;
        }
        for(j=0;j<N;j++)
        {
            double x,y;
            scanf("%lf %lf",&x,&y);
            a[j].r=sqrt(pow(x,2)+pow(y,2));
            a[j].angle=atan(y/x);
            if(a[j].angle<0)
                a[j].angle=(-1)*a[j].angle;
            if(x<0&&y>0)
                a[j].angle=3.1415926-a[j].angle;
            else
            {
                if(x<0&&y<0)
                    a[j].angle=3.1415926+a[j].angle;
                else
                {
                    if(x>0&&y<0)
                    {
                        a[j].angle=2*3.1415926-a[j].angle;
                    }
                    else
                    {
                        if(x==0&&y<0)
                            a[j].angle=3*3.1415926/2;
                        else
                        {
                            if(y==0&&x<0)
                                a[j].angle=3.1415926;
                        }
                    }
                }
            }
        }
        qsort(a,N,sizeof(struct jizuobiao),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<N;j++)
        {
            printf("(%.4lf,%.4lf)\n",a[j].r,a[j].angle);
        }
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926
struct polar
{
    double x;
    double y;
    double r;
    double th;
};

int cmp(const void*a,const void*b)
{
    struct polar *c=(struct polar *)a;
    struct polar *d=(struct polar *)b;
    if(c->th > d->th)
        return 1;
    else if(c->th < d->th)
        return -1;
    else
        if(c->r > d->r)
            return -1;
        else return 1;
}
int main()
{
    int T,i;
    int N,j;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        struct polar p[1000]={0};
        scanf("%d",&N);
        for(j=0;j<N;j++)
        {
            scanf("%lf",&p[j].x);
            scanf("%lf",&p[j].y);
            double X=pow(p[j].x,2.0);
            double Y=pow(p[j].y,2.0);
            p[j].r=sqrt(X+Y);
            p[j].th=atan2(p[j].y,p[j].x);
            if(p[j].th < 0.0)
            {
                p[j].th=2*(double)PI+p[j].th;
			}
        }
        qsort(p,N,sizeof(p[0]),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<N;j++)
        {
            printf("(%.4lf,%.4lf)\n",p[j].r,p[j].th);
        }

    }
    return 0;
}
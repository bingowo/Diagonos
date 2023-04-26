#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define pi 3.1415926

struct coo
{
    double x;
    double y;
    double p;
    double o;
};

int doublecmp(double a,double b)
{
    if(a==b)
        return 0;
    if(a<b)
        return -1;
    return 1;
}

int cmp(const void* a,const void* b)
{
    struct coo* c=(struct coo*)a;
    struct coo* d=(struct coo*)b;
    if(c->o!=d->o)
        return doublecmp(c->o,d->o);
        //return c->o-d->o;double型数据不能用减法比较，要不然会出错，要另写一个函数比较double
    else
        return doublecmp(d->p,c->p);
        //return c->p-d->p;
}

int main()
{

    struct coo *co;
    int T,i,N,j;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d",&N);
        co=(struct coo*)malloc(N*sizeof(struct coo));
        for(j=0;j<N;j++)
        {
            scanf("%lf %lf",&co[j].x,&co[j].y);
            co[j].p=sqrt(co[j].x*co[j].x+co[j].y*co[j].y);
            co[j].o=atan(co[j].y/co[j].x);//反三角函数
            if(co[j].o<0)
                co[j].o=co[j].o+atan(1.0)*8;
        }
        qsort(co,N,sizeof(struct coo),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<N;j++)
        {
            printf("(%.4f,%.4f)\n",co[j].p,co[j].o);
        }
    }
    return 0;
}

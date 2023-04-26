#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    long long x;
    long long y;
    long long dis;
}Point;

long long jdz(long long a)
{
    if(a>=0) return a;
    else return -a;
}

long long cdis(Point a,Point b)
{
    long long xx,yy;
    xx=jdz(a.x-b.x);
    yy=jdz(a.y-b.y);
    if(xx>=yy) return xx;
    else return yy;
}

int cmp(const void*a,const void*b)
{
    Point aa=*((Point*)a);
    Point bb=*((Point*)b);

    if(aa.dis<bb.dis) return -1;
    else if(aa.dis>bb.dis) return 1;
    else
    {
        if(aa.x<bb.x) return -1;
        else if(aa.x>bb.x) return 1;
        else
        {
            if(aa.y<bb.y) return -1;
            else if(aa.y>bb.y) return 1;
            else return 0;
        }
    }

}

int main()
{
    Point a;
    int n,i;
    scanf("%lld%lld",&a.x,&a.y);
    scanf("%d",&n);
    //printf("n=%d\n",n);
    //printf("%lld,%lld\n",a.x,a.y);
    Point *p=(Point*)malloc(sizeof(Point)*n);
    for(i=0;i<n;i++)
    {
        scanf("%lld%lld",&p[i].x,&p[i].y);
        p[i].dis=cdis(a,p[i]);

    }
    qsort(p,n,sizeof(Point),cmp);
    printf("%lld\n",p[0].dis);
    printf("%lld %lld\n",p[0].x,p[0].y);
    free(p);

}

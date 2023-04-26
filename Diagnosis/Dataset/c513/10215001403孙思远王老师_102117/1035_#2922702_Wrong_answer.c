#include <stdio.h>
#include <stdlib.h>

struct yuan
{
    int r;
    int h;
    int ce;
};
int cmp1(const void *a,const void *b)
{
    struct yuan *p1,*p2;
    p1=(struct yuan *)a;
    p2=(struct yuan *)b;
    return p2->r-p1->r;
}
int cmp2(const void *a,const void *b)
{
    struct yuan *p1,*p2;
    p1=(struct yuan *)a;
    p2=(struct yuan *)b;
    return p2->ce-p1->ce;
}
int main()
{
    int i,n,m;
    long long int x;
    scanf("%d%d",&n,&m);
    struct yuan yu[n];
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&yu[i].r,&yu[i].h);
    }
    qsort(yu,n,sizeof(yu[0]),cmp1);
    for(i=0;i<n;i++)
    {
        yu[i].ce=2*yu[i].r*yu[i].h;
    }
    x=yu[0].r*yu[0].r+yu[0].ce;
    yu[0].ce=0;
    qsort(yu,n,sizeof(yu[0]),cmp2);
    for(i=0;i<m-1;i++)
    {
        x+=yu[i].ce;
    }
    printf("%lld",x);
    return 0;
}

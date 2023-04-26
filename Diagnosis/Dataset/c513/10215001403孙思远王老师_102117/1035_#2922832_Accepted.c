#include <stdio.h>
#include <stdlib.h>

struct yuan
{
    unsigned long long int r;
    unsigned long long int h;
    unsigned long long int ce;
    unsigned long long int di;
};
int cmp1(const void *a,const void *b)
{
    struct yuan *p1,*p2;
    p1=(struct yuan *)a;
    p2=(struct yuan *)b;
    if(p2->r>p1->r)
        return 1;
    else
        return -1;
}
int cmp2(const void *a,const void *b)
{
    struct yuan *p1,*p2;
    p1=(struct yuan *)a;
    p2=(struct yuan *)b;
    if(p2->ce>p1->ce)
        return 1;
    else
        return -1;
}
int cmp3(const void *a,const void *b)
{
    unsigned long long int p1,p2;
    p1=*(long long int *)a;
    p2=*(long long int *)b;
    if(p2>p1)
        return 1;
    else
        return -1;
}
int main()
{
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    struct yuan yu[n];
    unsigned long long int x[n];
    for(i=0;i<n;i++)
        x[i]=0;
    for(i=0;i<n;i++)
    {
        scanf("%llu%llu",&yu[i].r,&yu[i].h);
        yu[i].ce=2*yu[i].r*yu[i].h;
        yu[i].di=yu[i].r*yu[i].r;
    }
    qsort(yu,n,sizeof(yu[0]),cmp1);
    for(j=0;j<=n-m;j++)
    {
        x[j]=yu[j].di+yu[j].ce;
        yu[j].ce=0;
        struct yuan yu2[n];
        for(i=0;i<n;i++)
        {
            yu2[i].ce=0;
        }
        for(i=0;i<n-j-1;i++)
        {
            yu2[i]=yu[i+j+1];
        }
        qsort(yu2,n,sizeof(yu2[0]),cmp2);
        for(i=0;i<m-1;i++)
        {
            x[j]+=yu2[i].ce;
        }
    }
    qsort(x,n,sizeof(x[0]),cmp3);
    printf("%llu",x[0]);
    return 0;
}

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct ball
{
    int r;
    int h;
    long long int rh;
};

int cmp1(const void*a,const void*b)
{
    struct ball *ap=(struct ball*)a;
    struct ball *bp=(struct ball*)b;
    if(ap->r!=bp->r)
    {
        if(ap->r>bp->r)
            return -1;
        else
            return 1;
    }
    else
    {
        if(ap->r>bp->r)
            return -1;
        else
            return 1;
    }
}

int cmp2(const void*a,const void*b)
{
    struct ball *ap=(struct ball*)a;
    struct ball *bp=(struct ball*)b;
    if(ap->rh!=bp->rh)
    {
        if(ap->rh>bp->rh)
            return -1;
        else
            return 1;
    }
    else
        return -1;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    struct ball a[1000];
    struct ball b[1000];
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&a[i].r,&a[i].h);
        a[i].rh=0;
    }
    for(i=0;i<n;i++)
        a[i].rh=(a[i].r)*(a[i].h);
    qsort(a,n,sizeof(struct ball),cmp2);
    for(i=0;i<m;i++)
    {
        b[i].r=a[i].r;b[i].h=a[i].h;b[i].rh=a[i].rh;
    }
    qsort(b,m,sizeof(struct ball),cmp1);
    long long int s1,s;
    s1=pow(b[0].r,2)+2*b[0].rh;
    s=s1;
    if(m==1)
        s=s1;
    else
    {
        for(i=1;i<m;i++)
            s=s+2*b[i].rh;
    }
    printf("%lld",s);
}

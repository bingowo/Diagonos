#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct ball
{
    int r;
    int h;
};

struct ball2
{
    int r2;
    int h2;
    long long int r2h2;
};

int cmp1(const void*a,const void*b)
{
    struct ball *ap=(struct ball*)a;
    struct ball *bp=(struct ball*)b;
    if(ap->r!=bp->r)
        return (bp->r-ap->r);
    else
        return -1;
}

int cmp2(const void*a,const void*b)
{
    struct ball2 *ap=(struct ball2*)a;
    struct ball2 *bp=(struct ball2*)b;
    if(ap->r2h2!=bp->r2h2)
    {
        if(ap->r2h2>bp->r2h2)
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
    struct ball2 b[1000];
    int i;
    for(i=0;i<n;i++)
        scanf("%d %d",&a[i].r,&a[i].h);
    qsort(a,n,sizeof(struct ball),cmp1);
    long long int s1,s;
    s1=pow(a[0].r,2);
    if(m==1)
        s=s1+2*a[0].r*a[0].h;
    else
    {
        s=s1+2*a[0].r*a[0].h;
        for(i=1;i<n;i++)
        {
            b[i-1].r2=a[i].r;b[i-1].h2=a[i-1].h;
            b[i-1].r2h2=(b[i-1].r2)*(b[i-1].h2);
        }
        qsort(b,n-1,sizeof(struct ball2),cmp2);
        for(i=1;i<m;i++)
            s=s+2*b[i-1].r2h2;
    }
    printf("%ld",s);
}
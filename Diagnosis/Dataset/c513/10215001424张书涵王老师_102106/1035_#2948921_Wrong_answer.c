#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct ball
{
    long long int r;
    long long int h;
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
    {
        if(ap->r>bp->r)
            return -1;
        else
            return 1;
    }
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    struct ball a[1000]={0,0,0};
    struct ball b[1000]={0,0,0};
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%lld %lld",&a[i].r,&a[i].h);
        a[i].rh=0;
    }
    for(i=0;i<n;i++)
        a[i].rh=(a[i].r)*(a[i].h);
    qsort(a,n,sizeof(struct ball),cmp1);
    long long int r1,h1,r2,h2,r3,h3;
    r1=a[0].r;h1=a[0].h;
    qsort(a,n,sizeof(struct ball),cmp2);
    r2=a[0].r;h2=a[0].h;
    if((pow(r1,2)+2*r1*h1)>(pow(r2,2)+2*r2*h2))
        {
            r3=r1;h3=h1;
        }
    else
        {
            r3=r2;h3=h2;
        }
    int j;
    for(i=0,j=0;i<m;j++)
    {
        if(a[j].r==r3&&a[j].h==h3);
        else
            b[i].r=a[j].r;b[i].h=a[j].h;b[i++].rh=a[j].rh;
    }
    qsort(b,m,sizeof(struct ball),cmp1);
    long long int s1=0,s=0;
    s1=pow(r3,2)+2*r3*h3;
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
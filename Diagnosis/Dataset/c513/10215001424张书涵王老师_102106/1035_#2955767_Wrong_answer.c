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
    scanf("%d %d",&n,&m);  //一共n个，挑选m个
    struct ball a[1000]={0,0,0};
    struct ball b[1000]={0,0,0};
    int i;
    for(i=0;i<n;i++)
        scanf("%lld %lld",&a[i].r,&a[i].h);
    for(i=0;i<n;i++)
        a[i].rh=(a[i].r)*(a[i].h);
    qsort(a,n,sizeof(struct ball),cmp1);//r大的搞出来
    long long int r1,h1;
    r1=a[0].r;h1=a[0].h;
    qsort(a,n,sizeof(struct ball),cmp2);//rh大的搞出来
    for(i=0;i<m;i++)
    {
        b[i].r=a[i].r;b[i].h=a[i].h;b[i].rh=a[i].rh;
    }
    qsort(b,m,sizeof(struct ball),cmp1);
    long long int s1=0,s=0;
    if(b[0].r==r1&&b[0].h==h1);
    else
    {
        long long int x1,x2;
        x1=pow(r1,2)+2*r1*h1;x2=pow(b[0].r,2)+2*b[0].rh;
         if(x1>=x2)
        {
            s=x1;
            qsort(b,m,sizeof(struct ball),cmp2);
            for(i=0;i<(m-1);i++)
                s=s+2*b[i].rh;
            printf("%lld",s);
            return 0;
        }
    }
    s1=pow(b[0].r,2)+2*b[0].rh;
    s=s1;
        for(i=1;i<m;i++)
            s=s+2*b[i].rh;
    printf("%lld",s);
}
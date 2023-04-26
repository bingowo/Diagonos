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
    if(ap->rh>bp->rh)
        return -1;
    else
        return 1;
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
    for(i=0;i<(m+1);i++)
    {
        b[i].r=a[i].r;b[i].h=a[i].h;b[i].rh=a[i].rh;
    }
    long long int s1=0,s=0;
    int j,count;
    for(i=0;i<n;i++)
    {
        s1=pow(a[i].r,2)+2*a[i].rh;
        for(j=0,count=0;count<(m-1);j++)
        {
            if(i==j);
            else
            {
                s1=s1+2*a[j].rh;count++;
            }
        }
        s=(s1>s)?s1:s;
    }
    printf("%lld",s);
}
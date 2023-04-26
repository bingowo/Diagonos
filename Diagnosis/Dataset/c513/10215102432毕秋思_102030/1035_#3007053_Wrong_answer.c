#include<stdio.h>
#include<stdlib.h>

struct Cylinder
{
    int r;
    int h;
    long long s;
    long long sd;
    long long sc;
}C[1100];

int cmp(const void *q1,const void *q2)
{
    struct Cylinder *p1=(struct Cylinder*)q1;
    struct Cylinder *p2=(struct Cylinder*)q2;
    if(p1->sc<p2->sc) return 1;
    else if(p1->sc>p2->sc) return -1;
    else
    {
        if(p1->r<p2->r) return 1;
        else return -1;
    }
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&C[i].r,&C[i].h);
        C[i].sd=C[i].r*C[i].r;
        C[i].sc=C[i].r*C[i].h*2;
        C[i].s=C[i].sd+C[i].sc;
    }
    qsort(C,n,sizeof(struct Cylinder),cmp);
    long long sum=0;
    for(int i=0;i<m-1;i++)
    {
        sum+=C[i].sc;
    }
    long long r_max=0;
    int fig=0;
    for(int i=0;i<n;i++)
    {
        if(r_max<C[i].r)
        {
            r_max=C[i].r;
            fig=i;
        }
    }
    if(fig>=m-1) sum+=C[fig].s;
    else sum=sum+C[fig].sd+C[m-1].sc;
    printf("%lld\n",sum);
    return 0;
}

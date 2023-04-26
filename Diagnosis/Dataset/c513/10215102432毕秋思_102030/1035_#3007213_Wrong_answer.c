#include<stdio.h>
#include<stdlib.h>
#define LONG_LONG_MAX 9223372036854775807

struct Cylinder
{
    int r;
    int h;
    long long s;
    long long sd;
    long long sc;
}cy[1100];

int cmp(const void *q1,const void *q2)
{
    struct Cylinder *p1=(struct Cylinder*)q1;
    struct Cylinder *p2=(struct Cylinder*)q2;
    if(p1->sc<p2->sc) return 1;
    else return -1;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    memset(&cy,0,sizeof(struct Cylinder));
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&cy[i].r,&cy[i].h);
        cy[i].sd=cy[i].r*cy[i].r;
        cy[i].sc=cy[i].r*cy[i].h*2;
        cy[i].s=cy[i].sd+cy[i].sc;
    }
    qsort(cy,n,sizeof(struct Cylinder),cmp);
    long long sum=0;
    for(int i=0;i<m;i++)
    {
        sum+=cy[i].sc;
    }
    long long r_max=0;
    long long sc_min=LONG_LONG_MAX;
    for(int i=0;i<m;i++)
    {
        if(r_max<cy[i].r) r_max=cy[i].r;
        if(sc_min>cy[i].sc) sc_min=cy[i].sc;
    }
    long long temp=0;
    for(int i=m;i<n;i++)
    {
        if(cy[i].s>(sc_min+r_max*r_max) && cy[i].r>=r_max && cy[i].s>temp)
        {
            temp=cy[i].s;
        }
    }
    if(temp!=0) sum=sum-sc_min+temp;
    else sum=sum+(r_max*r_max);
    printf("%lld\n",sum);
    return 0;
}

#include<stdio.h>

struct Cylinder
{
    int r;
    int h;
    long long rh;
}cy[1000];

int cmp1(const void *q1,const void *q2)
{
    struct Cylinder *p1=(struct Cylinder*)q1;
    struct Cylinder *p2=(struct Cylinder*)q2;
    if(p1->rh<p2->rh) return 1;
    else if(p1->rh>p2->rh) return -1;
    else if(p1->rh==p2->rh)
    {
        if(p1->r<p2->r) return 1;
        else return -1;
    }
}

int cmp2(int a,int b)
{
    if(a<b) return 1;
    else return -1;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&cy[i].r,&cy[i].h);
        cy[i].rh=cy[i].r*cy[i].h;
    }
    qsort(cy,n,sizeof(struct Cylinder),cmp1);
    long long sum=0;
    int sd[1000]={0};
    for(int i=0;i<m;i++)
    {
        sum+=(2*cy[i].rh);
        sd[i]=cy[i].r;
    }
    qsort(sd,m,sizeof(int),cmp2);
    sum+=(sd[0]*sd[0]);
    printf("%lld",sum);
    return 0;
}
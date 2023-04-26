#include<stdio.h>

struct Cylinder
{
    int r;
    int h;
}cy[1000];

int cmp(const void *q1,const void *q2)
{
    struct Cylinder *p1=(struct Cylinder*)q1;
    struct Cylinder *p2=(struct Cylinder*)q2;
    if(p1->r<p2->r) return 1;
    else return -1;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&cy[i].r,&cy[i].h);
    }
    qsort(cy,n,sizeof(struct Cylinder),cmp);
    int sum=cy[0].r*cy[0].r;
    for(int i=0;i<m;i++)
    {
        sum+=2*cy[i].r*cy[i].h;
    }
    printf("%d",sum);
    return 0;
}

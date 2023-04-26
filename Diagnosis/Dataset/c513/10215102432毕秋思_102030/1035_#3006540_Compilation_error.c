#include<stdio.h>
#include<stdlib.h>

struct Cylinder
{
    int r;
    int h;
    long long s;
    long long sd;
    long long sc;
}cy[1000];

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
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&cy[i].r,&cy[i].h);
        cy[i].sd=cy[i].r*cy[i].r;
        cy[i].sc=cy[i].r*cy[i].h*2;
        cy[i].s=cy[i].sd+cy[i].sc;
    }
    qsort(cy,n,sizeof(struct Cylinder),cmp);
    long long sum=0;
    for(int i=0;i<n;i++)
    {
        long long each_max=0;
        int qual=0;
        each_max+=cy[i].s;
        for(j=0;j<n;j++)
        {
            if(j==i) continue;
            if(qual==m-1) break;
            if(cy[i].r>=cy[j].r)
            {
                qual++;
                each_max+=cy[j].sc;
            }
        }
        if(qual==m-1&&each_max>sum) sum=each_max;
    }
    printf("%lld\n",sum);
    return 0;
}

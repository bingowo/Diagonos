#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct man
{
    int x;
    int y;
    int z;
};
int cmp(const void *a,const void *b)
{
    struct man *p1,*p2;
    p1=(struct man *)a;
    p2=(struct man *)b;
    if(p2->z!=p1->z)
        return p2->z-p1->z;
    else if(p2->x!=p1->x)
        return p1->x-p2->x;
    else
        return p1->y-p2->y;
}
int main()
{
    int n,i;
    scanf("%d",&n);
    struct man m[n];
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&m[i].x,&m[i].y);
        m[i].z=fabs(m[i].x)+fabs(m[i].y);
    }
    qsort(m,n,sizeof(m[0]),cmp);
    int d=fabs(m[0].x-m[1].x)+fabs(m[0].y-m[1].y);
    printf("%d\n",d);
    int ch,bu=0;
    for(i=0;i<n-1;i++)
    {
        ch=fabs(m[i].x-m[i+1].x)+fabs(m[i].y-m[i+1].y);
        if((ch%2)==1)
            bu+=log(ch)/log(2)+1;
        else
            break;
    }
    printf("%d",bu);
    return 0;
}

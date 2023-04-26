#include <stdio.h>
#include <stdlib.h>

typedef long long int LLD;

typedef struct
{
    LLD x,y,dis;
}DIS;

LLD llabs(LLD a)
{
    if(a < 0)
        return -a;
    else
        return a;
}

int cmp(const void*a,const void*b)
{
    DIS*st1 = (DIS*)a,*st2 = (DIS*)b;
    if(st1->dis > st2->dis)
        return 1;
    else if(st1->dis == st2->dis)
    {
        if(st1->x < st2->x)
            return -1;
        else if(st1->x == st1->x)
        {
            if(st1->y < st2->y)
                return -1;
            else
                return 1;
        }
        else
            return 1;
    }
    else
        return -1;
}

int main()
{
    int n,i;
    LLD x0,y0;
    scanf("%lld %lld",&x0,&y0);
    scanf("%d",&n);
    DIS*point;
    point = (DIS*)malloc(sizeof(DIS) * n);
    //DIS point[n + 1];
    for(i = 0;i < n;i++)
    {
        scanf("%lld %lld",&point[i].x,&point[i].y);
        point[i].dis = (llabs(point[i].x - x0) > llabs(point[i].y - y0))?llabs(point[i].x - x0):llabs(point[i].y - y0);
    }
    qsort(point,n,sizeof(DIS),cmp);
    printf("%lld\n%lld %lld\n",point[0].dis,point[0].x,point[0].y);
    free(point);
    return 0;
}
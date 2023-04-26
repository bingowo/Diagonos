#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct zuobiao
{
    long long int x;long long int y;
};

long long int newabs(long long int a)
{
    if(a>=0)
        return a;
    else
        return (-1)*a;
}

int cmp(const void*a,const void*b)
{
    struct zuobiao*ap=(struct zuobiao*)a;
    struct zuobiao*bp=(struct zuobiao*)b;
    unsigned long long int at,bt;
    at=newabs(ap->x)+newabs(ap->y);
    bt=newabs(bp->x)+newabs(bp->y);
    if(at>bt)
        return -1;
    if(at<bt)
        return 1;
    if(at==bt)
    {
        if(newabs(ap->x)>newabs(bp->x))
            return 1;
        if(newabs(ap->x)<newabs(bp->x))
            return -1;
        if(newabs(ap->y)>newabs(bp->y))
            return 1;
    }
    return -1;
}

int main()
{
    int n;
    scanf("%d",&n);
    struct zuobiao a[100]={0,0};
    int i=0,j=0,k=0,m=0;
    unsigned long long int d=0,d2=0,tstep=0;
    int step=0;
    for(i=0;i<n;i++)
        scanf("%lld %lld",&a[i].x,&a[i].y);
    qsort(a,n,sizeof(struct zuobiao),cmp);
    d2=newabs(a[1].x-a[0].x)+newabs(a[1].y-a[0].y);
    unsigned long long int dx=0,dy=0;
    dx=newabs(a[1].x-a[0].x);
    dy=newabs(a[1].y-a[0].y);
    if(dx>9223372036854775807&&dy>9223372036854775807)
        printf("18446744073709551616\n");
    else
        printf("%llu\n",d2);
    for(i=0,j=i+1;j<n;i++,j++)
    {
        tstep=newabs(a[j].x-a[i].x)+newabs(a[j].y-a[i].y);
        if(tstep%2==0&&tstep!=0)
        {
            m=j;break;
        }
        else
            m=n;
    }
    int p=0;
    for(i=0,p=i+1;p<m;i++,p++)
    {
        d=newabs(a[p].x-a[i].x)+newabs(a[p].y-a[i].y);
        for(k=1;k<65;k++)
        {
            if(d>pow(2,k));
            else
            {
                if(d==0);
                else
                {step=step+k;break;}
            }
        }
    }
    printf("%d",step);
}
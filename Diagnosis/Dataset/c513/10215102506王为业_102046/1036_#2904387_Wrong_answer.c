//sort\1036.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>

//#define LOCAL
#define TRUE 1
#define FALSE 0
typedef long long LL;
typedef unsigned long long ULL;
ULL ullabs(LL x)
{
    return x<0?-x:x;
}

struct dis{
    LL x,y;
    ULL d;
};

typedef struct dis mdis;
mdis arr[110];
int isach(ULL dx,ULL dy,int steps)
{
    if(steps==0){
        if(dx==0&&dy==0)
            return TRUE;
        else
            return FALSE;
    }

    if(steps==1){
        if(dx+dy==1)
        return TRUE;
        else
        return FALSE;
    }
    ULL move=1<<(steps-1);
    ULL ndx=move>dx?move-dx:dx-move;
    ULL ndy=move>dy?move-dy:dy-move;
    if(ndx<=dx&&ndy<=dy)//discover that maintain is important,too
        return isach(ndx,dy,steps-1)||isach(dx,ndy,steps-1);
    else if(ndx<=dx)
        return isach(ndx,dy,steps-1);
    else if(ndy<=dy)
        return isach(dx,ndy,steps-1);
    else
        return FALSE;
}
int getsteps(mdis*ap,mdis*bp)
{
    ULL dx=ullabs(ap->x -bp->x);
    ULL dy=ullabs(ap->y -bp->y);
    int steps=1;
    if((dx&1)^(dy&1))return -1;
    while(1<<(steps-1) < dx<<1 || 1<<(steps-1) < dy<<1)
        ++steps;
    --steps;

    while(steps>0&&isach(dx,dy,steps)==FALSE)
        --steps;
    if(steps==0)return -1;
    else return steps;
}

int discmp(mdis*a,mdis*b)
{
    if(a->d==b->d){
        if(a->x==b->x){
            return a->y > b->y?1:-1;
        }
        return a->x > b->x?1:-1;
    }else{
        return a->d > b->d?-1:1;
    }
}

int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    int n;
    scanf("%d",&n);
    for(int in=0;in<n;++in){
        scanf("%lld %lld",&arr[in].x,&arr[in].y);
        arr[in].d=ullabs(arr[in].x)+ullabs(arr[in].y);
    }
    qsort(arr,n,sizeof(arr[0]),discmp);
    printf("%llu\n",ullabs(arr[0].x-arr[1].x)+ullabs(arr[0].y-arr[1].y));
    int total_steps=0;
    int temstep;
    for(int in=0;in<n-1;++in){
        if((temstep=getsteps(&arr[in],&arr[in+1]))!=-1)
            total_steps+=temstep;
        else
            break;
    }
    printf("%d",total_steps);
}

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
long long directions[4][2]={0,1,0,-1,1,0,-1,0};
int isOKsteps(ULL dx,ULL dy,LL steps)
{
    if(steps==0){
        if(dx==0&&dy==0)
            return TRUE;
        else
            return FALSE;
    }
    else{
        if(dx==0&&dy==0)
            return FALSE;
    }
    ULL thedis=1<<(steps-1);
    ULL ex=ullabs(thedis-dx);
    ULL ey=ullabs(thedis-dy);
    if(ex==ey){
        return isOKsteps(ex,dy,steps-1)||isOKsteps(dx,ey,steps-1);
    }else
        return ex<ey?isOKsteps(ex,dy,steps-1):isOKsteps(dx,ey,steps-1);
}
LL getstep(mdis *a,mdis *b)
{
    ULL dx=ullabs(a->x - b->x);
    ULL dy=ullabs(a->y - b->y);
    if(dx==0&&dy==0)
        return 0;
    if((dx&1)^(dy&1)){
        LL steps=1;
        while(1<<(steps-1) < dx||1<<(steps-1) <dy){
            ++steps;
        }
        while(steps>=1&&isOKsteps(dx,dy,steps))--steps;
        //get wrong
        if(steps==0)
            return -1;
        else
            return steps+1;//key
    }else{
        return -1;
    }
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
    ULL total_steps=0;
    LL temstep;
    for(int in=0;in<n-1;++in){//available start
        if((temstep=getstep(&arr[in],&arr[in+1]))==-1)
            break;
        else
            total_steps+=temstep;
    }
    printf("%llu",total_steps);
}

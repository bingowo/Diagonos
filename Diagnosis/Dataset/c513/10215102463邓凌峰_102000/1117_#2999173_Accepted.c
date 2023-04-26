#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define LEN 550
#define BigNUm 10007
#define Max 1000000

typedef long long lli;

typedef struct{
    lli x;
    lli y;
    lli distance;
}P;

lli llabs(lli x){ return x>0?x:-x;}

lli countDistance(P p_0,P point){
    lli disX=llabs(p_0.x-point.x);
    lli disY=llabs(p_0.y-point.y);
    return disX>disY?disX:disY;
}

int cmp(const void *a,const void *b){
    P pa=*(P*)a,pb=*(P*)b;
    if(pa.distance!=pb.distance){
        return pa.distance>pb.distance?1:-1;
    }
    else if(pa.x!=pb.x){
        return pa.x>pb.x?1:-1;
    }
    else return pa.y>pb.y?1:-1;
}




int main(){
    P point_0={0};
P points[Max]={0};
    scanf("%lld%lld",&point_0.x,&point_0.y);
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld%lld",&points[i].x,&points[i].y);
        points[i].distance=countDistance(point_0,points[i]);
    }
    qsort(points,n,sizeof(points[0]),cmp);

    printf("%lld\n%lld %lld",points[0].distance,points[0].x,points[0].y);


    return 0;

}

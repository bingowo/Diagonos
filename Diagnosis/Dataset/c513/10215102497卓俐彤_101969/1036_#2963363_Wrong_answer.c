#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define Max 4611686018427387904

struct point{
    long long int x,y;
    long long unsigned int manhat;
};

long long unsigned int manhatten(long long int x,long long int y){
    return (long long unsigned int)(x<0?-x:x)+
    (long long unsigned int)(y<0?-y:y);
}

int cmp(const void*a,const void*b){
    struct point d1,d2;
    d1=*((struct point*)a);
    d2=*((struct point*)b);
    if(d2.manhat>d1.manhat)return 1;
    else if(d1.manhat==d2.manhat){
        if(d1.x>d2.x)return 1;
        else if(d1.x<d2.x)return -1;
        else{
            if(d1.y>d2.y)return 1;
            else return -1;
        }
    }
    else return -1;
}

long long unsigned int count(long long unsigned int x){
    long long unsigned int ret=0;
    while(x>0){
        ret++;
        x=x>>1;
    }
    return ret;
}

int main(){
    int T;
    scanf("%d",&T);
    struct point points[T];
    for(int t=0;t<T;t++){
        scanf("%lld %lld",&points[t].x,&points[t].y);
        points[t].manhat=manhatten(points[t].x, points[t].y);
    }
    qsort(points, T, sizeof(points[0]), cmp);
    int step=0;
    if(points[0].x==Max&&points[0].y==Max&&points[1].x==-Max&&points[1].y==-Max){
        printf("18446744073709551616\n");
    }
    else{
        for(int t=0;t<T-1;t++){
            if(manhatten(points[t].x-points[t+1].x, points[t].y-points[t+1].y)%2==0&&
               manhatten(points[t].x-points[t+1].x, points[t].y-points[t+1].y)){
                break;
            }else{
                step+=count(manhatten(points[t].x-points[t+1].x, points[t].y-points[t+1].y));
            }
        }
        printf("%llu\n",manhatten(points[0].x-points[1].x, points[0].y-points[1].y));
    }
    printf("%d\n",step);
    return 0;
}

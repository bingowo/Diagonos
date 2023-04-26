#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10005

typedef struct
{
    double v,dist;
}car;

int canCatch(car a,car b)
{
    if(a.dist/a.v<=b.dist/b.v)return 1;
    else return 0;
}

int main()
{
    car lastcar;
    scanf("%lf",&lastcar.dist);
    car c[N];int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        double temp;
        scanf("%lf %lf",&temp,&c[i].v);
        c[i].dist=lastcar.dist-temp;
    }
    car spc;
    spc.dist=c[0].dist;
    spc.v=c[0].v;
    for(int i=n-1;i>0;--i){
        if(!canCatch(c[i],c[i-1])){
            //printf("yes\n");
            spc.dist=c[i].dist;
            spc.v=c[i].v;
        }
    }
    double time = spc.dist/spc.v;
    //printf("%.6lf %.6lf\n",spc.dist,spc.v);
    lastcar.v=lastcar.dist/time;
    printf("%.6lf",lastcar.v);
    return 0;
}
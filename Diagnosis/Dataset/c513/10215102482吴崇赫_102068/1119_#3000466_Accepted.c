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

int cmp(const void* a,const void* b)
{
    car* ca=(car*)a;
    car* cb=(car*)b;
    return ca->dist/ca->v<cb->dist/cb->v?1:-1;
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
    qsort(c,n,sizeof(c[0]),cmp);
    car spc;
    spc.dist=c[0].dist;
    spc.v=c[0].v;
    double time = spc.dist/spc.v;
    lastcar.v=lastcar.dist/time;
    printf("%.6lf",lastcar.v);
    return 0;
}

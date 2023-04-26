#include<stdio.h>
#include<stdlib.h>

typedef struct{
    long long x,y,d;
}point;

long long cmp(const void *a,const void *b){
    point *p1=(poinnt *)a,*p2=(point *)b;
    long long t=p1->d-p2->d,tx=p1->x-p2->x,ty=p1->y-p2->y;
    if(t)return t;
    else if(tx)return tx;
    else return ty;
}

int main(){
    long long x0,y0;
    scanf("%lld %lld",&x0,&y0);
    int n;
    scanf("%d",&n);
    point g[n];
    for(int i=0;i<n;i++){
        scanf("%lld %lld",&g[i].x,&g[i].y);
        long long d1=g[i].x-x0,d2=g[i].y-y0;
        if(d1<0)d1*=-1;
        if(d2<0)d2*=-1;
        if(d1>d2)g[i].d=d1;
        else g[i].d=d2;
    }
    qsort(g,n,sizeof(point),cmp);
    printf("%lld\n",g[0].d);
    printf("%lld %lld\n",g[0].x,g[0].y);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct point{
    double p;
    double o;
    double x;
    double y;
};

int compar(const void*a,const void*b){
    struct point p1,p2;
    p1=*((struct point*)a);
    p2=*((struct point*)b);
    if(p1.o==p2.o){
        if(p2.p<p1.p)return -1;
        else return 1;
    }
    else{
        if(p2.o<p1.o)return 1;
        else return -1;
    }
}

int main(){
    int T;
    scanf("%d",&T);
    double pi=4*atan(1);
    for(int t=0;t<T;t++){
        printf("case #%d:\n",t);
        int N;
        scanf("%d",&N);
        struct point points[N];
        for(int n=0;n<N;n++){
            scanf("%lf %lf",&points[n].x,&points[n].y);
            points[n].p=pow(points[n].x,2)+pow(points[n].y,2);
            points[n].p=sqrt(points[n].p);
            if(points[n].x<0){
                if(points[n].y<0)points[n].o=pi+atan(points[n].y/points[n].x);
                else points[n].o=pi+atan(points[n].y/points[n].x);
            }else{
                if(points[n].y<0)points[n].o=2*pi+atan(points[n].y/points[n].x);
                else points[n].o=atan(points[n].y/points[n].x);
            }
        }
        qsort(points,N,sizeof(points[0]),compar);
        for(int n=0;n<N;n++)printf("(%.4f,%.4f)\n",points[n].p,points[n].o);
    }
    return 0;
}

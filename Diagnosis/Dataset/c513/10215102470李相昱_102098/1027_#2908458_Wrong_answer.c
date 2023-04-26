#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.14159265
typedef struct {
    double x;
    double y;
    double p;
    double ang;
}locate;
int cmp(const void *p1,const void *p2){
    locate *a = (locate *)p1;
    locate *b = (locate *)p2;
    if(a->ang < b->ang){
        return -1;
    }else if(a->ang > b->ang){
        return 1;
    }else if(a->p < b->p){
        return 1;
    }else {
        return -1;
    }
}
int main() {
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int N;
        scanf("%d",&N);
        locate a[N];
        for(int j =0;j<N;j++){
            scanf("%lf",&a[j].x);
            scanf("%lf",&a[j].y);
            a[j].p = sqrt(a[j].x*a[j].x+a[j].y*a[j].y);
            if(atan2(a[j].x,a[j].y)<0){
                a[j].ang=atan2(a[j].y,a[j].x)+2*PI;
            }else{
                a[j].ang=atan2(a[j].y,a[j].x);
            }
        }
        qsort(a,N,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        for(int q=0;q<N;q++){
            printf("(%.4lf,%.4lf)\n",a[q].p,a[q].ang);
        }
    }
    return 0;
}

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

typedef struct R{
    double r;
    double angle;
};

int cmp(const void *a, const void *b){
    const struct R *r1=a, *r2=b;
    if(r1->angle - r2->angle >0) return -1;
    else if(r1->angle - r2->angle <0) return 1;
    else{
        if(r1->r - r2->r >0) return -1;
        else return 1;
    }
}

int main() {
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        int n;
        scanf("%d",&n);
        struct R a[n];
        struct R *p=a;
        for(int j=0;j<n;j++){
            double x,y;
            scanf("%lf %lf",&x,&y);
            double ang = atan2(y,x);
            if(ang<0) ang += atan(1.0)*8;
            p->angle = ang;
            p->r = hypot(x,y);
            p++;
        }
        qsort(a,n,sizeof(struct R),cmp);
        for(int j=0;j<n;j++){
            printf("(%.4lf,%.4lf\n)",a[j].r,a[j].angle);
        }
    }
    return 0;
}

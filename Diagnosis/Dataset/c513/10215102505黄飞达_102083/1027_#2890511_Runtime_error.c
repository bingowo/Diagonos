#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define pi 3.14159;
typedef struct dot{
    double p, r;
}dot;


int cmp(const void *a, const void *b){
    dot *x = (dot*)a;
    dot *y = (dot*)b;
    if (x->r != y->r) return x->r > y->r ? 1 : -1;
    else return y->p > x->p ? 1 : -1;
}

int main(){
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++){
        int n;
        scanf("%d", &n);
        dot dotarr[101];
        for (int i = 0; i < n; i++){
            dot d0;
            double x, y;
            scanf("%lf %lf", &x, &y);
            d0.r = atan2(y,x);
            d0.p = sqrt(x*x+y*y);
            if (y<0) d0.r += 2*pi;
            
            dotarr[i]=d0;
        }
        qsort(dotarr, n, sizeof(dot), cmp);
        printf("case #%d:\n", t);
        for (int i = 0; i < n; i++) printf("(%.4lf,%.4lf)\n", dotarr[i].p, dotarr[i].r);


    }
    return 0;
}
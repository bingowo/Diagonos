#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    double row;
    double theta;
} P;

int cmp(const void* m, const void* n) {
    P *a = (P*)m, *b = (P*)n;
    if(fabs(a->theta-b->theta) < 1e-4){
        return b->row > a->row;
    }else {
        return a->theta > b->theta;
    }
}
 
int main()
{
    int T; scanf("%d",&T);
    double pi = 8.0 * atan(1.0);
    for(int j=0; j<T; ++j ){
        int N; scanf("%d",&N);
        P a[1000];
        for(int i=0; i<N; ++i){
            double x, y;
            scanf("%lf %lf",&x,&y);
            a[i].row = sqrt(x*x + y*y);
            a[i].theta = atan2(y, x);
            if(a[i].theta < 0)
                a[i].theta += pi;
        }
        qsort(a, N, sizeof(P), cmp);
        printf("case #%d:\n",j);
        for(int i=0; i<N; ++i)
            printf("(%.4f,%.4f)\n",a[i].row,a[i].theta);
    }
    return 0;
}

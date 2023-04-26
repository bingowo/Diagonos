#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    double row;
    double theta;
} P;

int cmp(const void* m, const void* n) {
    P *a = (P*)m, *b = (P*)n;
    if(fabs(a->theta-b->theta) < 1e-6){
        return b->row > a->row;
    }else {
        return a->theta > b->theta;
    }
}
 
int main()
{
    int T; scanf("%d",&T);
    for(int j=0; j<T; ++j ){
        int N; scanf("%d",&N);
        P a[1000];
        for(int i=0; i<N; ++i){
            double x, y;
            scanf("%lf %lf",&x,&y);
            a[i].row = sqrt(x*x + y*y);
            if(fabs(y)<1e-6) a[i].theta = x>0?0: 4*atan(1);
            else if(fabs(x)<1e-6) a[i].theta = y>0?2*atan(1) : 6*atan(1);
            else if(x > 0) {
                a[i].theta = atan(y/x);
                if(y < 0) a[i].theta += 8 * atan(1);
            }else {
                a[i].theta = atan(y/x) + 4*atan(1);
            }
        }
        qsort(a, N, sizeof(P), cmp);
        printf("case #%d:\n",j);
        for(int i=0; i<N; ++i)
            printf("(%.4f,%.4f)\n",a[i].row,a[i].theta);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pai 3.1415926

typedef struct{
    double zX,zY;
    double jX,jY;
}POINT;

int cmp(const void *a, const void *b){
    POINT *pa = (POINT*)a, *pb = (POINT*)b;
    if(pa->jY != pb->jY) return (pa->jY - pb->jY);
    return (pb->jX - pa->jX);
}

int main()
{
    int T,R;
    scanf("%d",&T);
    for(R = 0; R < T; R++){
        int N;
        scanf("%d",&N);

        POINT *p = (POINT*)malloc(N*sizeof(POINT));
        for(int k = 0; k < N; k++){
            scanf("%lf%lf",&(p[k].zX),&(p[k].zY));

            double fi = sqrt(p[k].zX * p[k].zX + p[k].zY * p[k].zY);
            double tan = p[k].zY / p[k].zX;
            p[k].jX = fi;
            p[k].jY = atan(tan) < 0 ? atan(tan)+2*pai : atan(tan);
        }

        qsort(p,N,sizeof(POINT),cmp);

        printf("case #%d:\n",R);
        for(int k = 0; k <N; k++){
            printf("(%.4lf,%.4lf)\n",p[k].jX,p[k].jY);
        }
    }
    return 0;
}

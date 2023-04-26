#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pai 3.1415926

typedef struct{
    double X,Y;
}POINT;

int cmp(const void *a, const void *b){
    POINT *pa = (POINT*)a, *pb = (POINT*)b;

    if(pa->Y > pb->Y) return 1;
    if(pa->Y < pb->Y) return -1;
    if(pa->X > pb->X) return -1;
    if(pa->X < pb->X) return 1;
    return 0;


    //if(pa->Y != pb->Y) return (pa->Y - pb->Y);
    //else return (pb->X - pa->X);
}

int main()
{
    int T,R;
    scanf("%d",&T);
    for(R = 0; R < T; R++){
        int N;
        scanf("%d",&N);

        double tempx,tempy;
        POINT p[1000];
        for(int k = 0; k < N; k++){
            scanf("%lf%lf",&tempx,&tempy);

            double fi = sqrt(tempx * tempx + tempy * tempy);
            p[k].X = fi;

            if(tempx == 0){ //y
                if(tempy > 0) p[k].Y = pai / 2;
                else if(tempy < 0) p[k].Y = pai * 3 / 2;
                else if(tempy == 0) p[k].Y = 0.0000;
                continue;
            }

            double tan = tempy / tempx;
            p[k].Y = atan(tan);

            if(tempy <= 0 && tempx < 0) p[k].Y += pai;   //d 3
            else if(tempy < 0 && tempx > 0) p[k].Y += 2 * pai;  //d 4
            else if(tempy >= 0 && tempx < 0) p[k].Y += pai;  //d 2
        }

        qsort(p,N,sizeof(POINT),cmp);

        printf("case #%d:\n",R);
        for(int k = 0; k <N; k++){
            printf("(%.4lf,%.4lf)\n",p[k].X,p[k].Y);

        }
    }
    return 0;
}

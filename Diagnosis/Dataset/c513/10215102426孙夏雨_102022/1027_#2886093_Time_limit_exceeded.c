#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    double L;
    double A;
} JI;

double q(double x)
{
    if(x-1<0.00000001) return 1.0;
    double max=x>1 ? x:1;
    double min=0.0;
    double e=(max+min)/2.0;
    while(fabs(e*e-x)>=0.00000001){
        if(e*e-x>0) {
            max=e;
            e=(max+min)/2;
        }
        else {
            min=e;
            e=(max+min)/2;
        }
    }
    return e;
}

int cmp(const void* p3,const void* p4)
{
    JI* p1=(JI* )p3;
    JI* p2=(JI* )p4;
    if((p1->A)>(p2->A)) return 1;
    else if((p1->A)<(p2->A)) return -1;
    else{
        if((p1->L)>(p2->L)) return -1;
        else return 1;
    }
}

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int N=0;
        scanf("%d",&N);
        JI* p=(JI* )malloc(N*sizeof(JI));
        for(int i=0;i<N;i++){
            double x,y,z;
            scanf("%lf %lf",&x,&y);
            (p+i)->A=(atan2(y,x))>=0 ? atan2(y,x):3.1415926*2+atan2(y,x);
            z=q(x*x+y*y);
            (p+i)->L=z;
        }
        qsort(p,N,sizeof(JI),cmp);
        printf("case #%d:\n",t);
        for(int ii=0;ii<N;ii++) printf("(%.4f,%.4f)\n",(p+ii)->L,(p+ii)->A);
    }
    return 0;
}

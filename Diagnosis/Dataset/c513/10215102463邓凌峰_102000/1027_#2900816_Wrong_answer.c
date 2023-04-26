#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define pi 3.1415926

typedef struct
{
    double x;
    double y;
    double th;
    double r;
}Point;

int cmp(const void *a,const void *b)
{
    Point pa=*(Point*)a,pb=*(Point*)b;
    if(fabs(pa.th-pb.th)>0.00000001){
        return pa.th-pb.th>0.0000001?1:-1;
    }
    else return pa.r-pb.r>0.00000001?-1:1;
}



int main()
{
    int T;scanf("%d",&T);
    for(int i=0;i<T;i++){
        printf("s0\n");
        int N;scanf("%d",&N);
        Point points[N];
        for(int j=0;j<N;j++){
            scanf("%lf %lf",&points[j].x,&points[j].y);
            points[j].r=sqrt(points[j].x*points[j].x+points[j].y*points[j].y);
            points[j].th=atan2(points[j].y,points[j].x);
            if(points[j].th<0)points[j].th+=2*pi;
        }
        printf("s1\n");
        qsort(points,N,sizeof(Point),cmp);
        printf("case #%d:\n",i);
        for(int k=0;k<N;k++){
            printf("(%.4f,%.4f)\n",points[k].r,points[k].th);
        }


    }
	return 0;
}

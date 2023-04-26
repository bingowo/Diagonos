#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct point{

};

int main(){
    int T;
    scanf("%d",&T);
    double pi=3.14159265;
    for(int t=0;t<T;t++){
        printf("case #%d:\n",t);
        int N;
        scanf("%d",&N);
        for(int n=0;n<N;n++){
            double x,y;
            scanf("%lf %lf",&x,&y);
            double p,o;
            p=pow(x,2)+pow(y,2);
            p=sqrt(p);
            o=atan2(x,y);
            printf("(%.4f,%.4f)\n",p,o);
        }
    }
    return 0;
}

#include <stdio.h>
#include <math.h>


typedef struct Polar{
    double len;
    double ang;
}P;

void convert(P *p, double x, double y){
    p->len = pow(x*x + y*y, 0.5);
    p->ang = atan(y/x);
    if(p->ang <= 0) {
        if(y<0)
            p->ang = (2*M_PI + p->ang);
            
        else
            if(x<0)
                p->ang = (M_PI + p->ang);
    }
    else{
        if(x<0 || y <0)
            p->ang = (M_PI + p->ang);
    }
}

bool cmp(P a, P b){
    if(a.ang!=b.ang) return a.ang<b.ang;
    else return a.len>b.len;
}

int main(){
    int T;
    scanf("%d",&T);
    for(int i = 0; i < T; i++){
        int N;
        scanf("%d",&N);
        P *p = (P*)malloc(sizeof(P)*(N+1));
        for(int j = 0; j < N; j++){
            double x, y;
            scanf("%d %d",&x,&y);
            convert(p+j, x, y);
        }
        sort(p, p+N, cmp);
        printf("case #%d:\n", i);
        for(int j = 0; j < N; j++)
            printf("(%.4f,%.4f)\n", p[j].len, p[j].ang);
    }
    return 0;
}
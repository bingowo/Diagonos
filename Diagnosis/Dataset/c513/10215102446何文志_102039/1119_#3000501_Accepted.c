#include <stdio.h>
#include <stdlib.h>
typedef struct Car{
    int d;//与目的地的距离
    int k;//与最后一辆车的距离
    int s;//速度
    double t;//到达目的地的时间
}car;

double max(double x, double y){
    return x>y ? x : y;
}

int main()
{
    car c0 = {0,0,0};
    scanf("%d",&c0.d);
    int n = 0;
    scanf("%d",&n);
    car c[n+1];memset(c,0,(n+1)*sizeof(car));
    c[0] = c0;
    for(int i = 1;i<=n;i++){
        scanf("%d%d",&c[i].k, &c[i].s);
        c[i].d = c[0].d - c[i].k;
    }

    c[1].t = (1.0*c[1].d/c[1].s);
    for(int i = 2;i<=n;i++){
        c[i].t = max(c[i-1].t, (1.0*c[i].d)/c[i].s);
    }
    c[0].t = c[n].t;
//    for(int i = 0;i<=n;i++){
//        printf("%d: %d %d %d %f\n",i,c[i].d,c[i].k,c[i].s,c[i].t);
//    }
    double res = c[0].d/c[0].t;
    printf("%.6f\n",res);
    return 0;
}

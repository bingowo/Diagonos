#include <stdio.h>

struct CAR{
    double away;
    double speed;
    double time;
};
struct CAR c[1001];
int main() {
    int d,n;
    scanf("%d%d",&d,&n);
    double k,s;
    for(int i=0;i<n;i++)
    {
        scanf("%lf%lf",&k,&s);
        c[i].away=d-k;
        c[i].speed=s;
        c[i].time=c[i].away/c[i].speed;
    }

    double t;
    for(int j=0;j<n;j++) {
        if (t < c[j].time) {
            t = c[j].time;
        }
    }
    double sp=d/t;
    printf("%.6f\n",sp);
    return 0;
}

#include <stdio.h>

int main() {
    int d,n;
    scanf("%d%d",&d,&n);
    double k,s;
    double c[1001];
    for(int i=0;i<n;i++)
    {
        scanf("%lf%lf",&k,&s);
        c[i]=(d-k)/s;
    }
    double t;
    for(int j=0;j<n;j++) {
        if (t < c[j]) {
            t = c[j];
        }
    }
    double sp=d/t;
    printf("%.6f\n",sp);
    return 0;
}

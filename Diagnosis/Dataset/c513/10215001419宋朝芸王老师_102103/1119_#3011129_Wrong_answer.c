#include <stdio.h>
#include <stdlib.h>

double max(double a, double b){
    if(a > b) return a;
    else return b;
}

int main()
{
    int d, n;
    double maxtime = 0;
    scanf("%d%d",&d,&n);

    int distance, speed;
    double time;
    for(int i = 0; i < n; i++){
        scanf("%d%d",&distance,&speed);
        time = (d-distance)/speed;
        maxtime = max(time, maxtime);
    }

    printf("%.6lf",d/maxtime);

    return 0;
}

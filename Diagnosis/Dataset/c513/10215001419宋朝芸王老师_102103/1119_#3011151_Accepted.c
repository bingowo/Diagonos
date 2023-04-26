#include <stdio.h>
#include <stdlib.h>

double max(double a, double b){
    if(a > b) return 1;
    else return 0;
}

int main()
{
    int d, n;
    double tar_time = 0;
    scanf("%d%d",&d,&n);

    double distance, speed, tar_distance, tar_speed;
    double time;
    for(int i = 0; i < n; i++){
        scanf("%lf%lf",&distance,&speed);
        time = (d-distance)/speed;
        if(max(time, tar_time) == 1){
            tar_time = time;
            tar_distance = distance;
            tar_speed = speed;
        }
    }

    tar_time = d/(d-tar_distance);
        //it's temp, not time
    printf("%.6lf",tar_time*tar_speed);

    return 0;
}

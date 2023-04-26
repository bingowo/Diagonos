#include<stdio.h>
int main(){
    int dis, n; scanf("%d%d", &dis, &n);
    int firstDis, firstSpeed; scanf("%d%d", &firstDis, &firstSpeed);
    double maxTime = (dis - firstDis) * 1.0 / firstSpeed; 
    for (int i = 0; i < n - 1; i++){
        int nextDis, nextSpeed; scanf("%d%d", &nextDis, &nextSpeed);
        double time = (dis - nextDis) * 1.0 / nextSpeed;
        if (time > maxTime){
            maxTime = time;
            firstSpeed = nextSpeed;
            firstDis = nextDis;
        }
    }
    double res = dis * 1.0 / (dis - firstDis) * firstSpeed;
    printf("%.6f\n", res);
    return 0;
}
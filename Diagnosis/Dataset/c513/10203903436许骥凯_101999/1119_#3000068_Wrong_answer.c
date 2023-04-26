#include<stdio.h>

int main(){
    int dis, n; scanf("%d%d", &dis, &n);
    int firstDis, firstSpeed; scanf("%d%d", &firstDis, &firstSpeed);
    int maxTime = (dis - firstDis) / firstSpeed; 
    for (int i = 0; i < n - 1; i++){
        int nextDis, nextSpeed; scanf("%d%d", &nextDis, &nextSpeed);
        int time = (dis - nextDis) / nextSpeed;
        if (time > maxTime){
            maxTime = time;
            firstSpeed = nextSpeed;
            firstDis = nextDis;
        }
    }
    double res = dis * firstSpeed * 1.0 / (dis - firstDis);
    printf("%.6f\n", res);
    return 0;
}
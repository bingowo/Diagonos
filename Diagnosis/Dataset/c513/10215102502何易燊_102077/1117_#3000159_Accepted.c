#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>

long long max(long long a, long long b){
    return a < b ? b : a;
}

long long newabs(long long a){
    if (a < 0){
        a = -a;
    }
    return a;
}

int main(){
    long long x0, y0, n, xi, yi;
    scanf("%lld %lld", &x0, &y0);
    scanf("%lld", &n);
    long long distance = 1e17, xdis, ydis;
    for (int i = 0; i < n; i++){
        scanf("%lld %lld", &xi, &yi);
        long long temp = max(newabs(xi - x0), newabs(yi - y0));
        if (distance > temp){
            distance = temp;
            xdis = xi;
            ydis = yi;
        }
        else if (distance == temp){
            if (xdis > xi){
                xdis = xi;
                ydis = yi;
            }
            else if (xdis == xi){
                if (ydis > yi){
                    xdis = xi;
                    ydis = yi;
                }
            }
        }
    }
    printf("%lld\n%lld %lld", distance, xdis, ydis);
    system("pause");
    return 0;
}
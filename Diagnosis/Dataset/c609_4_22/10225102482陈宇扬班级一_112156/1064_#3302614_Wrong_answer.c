#include <stdio.h>
int spendPower(int x, int y);

int main(){
    int x;// 长
    int y;// 宽
    scanf("%d%d", &x, &y);
    int ans = spendPower(x, y);
    printf("%d", ans);
    return 0;
}

int spendPower(int x, int y){
    int minPower;
    int cnt;
    if(x == y){
        minPower = 2 * (x + y);
    }else if(x > y){
        cnt = x / y;
        minPower = cnt * 4 * y;
    }else if(x < y){
        cnt = y / x;
        minPower = cnt * 4 * x;
    }
    return minPower;
}


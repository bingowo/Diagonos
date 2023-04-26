#include <stdio.h>
#define LL long long
LL spendPower(LL x, LL y);

int main(){
    LL x;// 长
    LL y;// 宽
    scanf("%lld %lld", &x, &y);
    LL ans = spendPower(x, y);
    printf("%lld", ans);
    return 0;
}

LL spendPower(LL x, LL y){
    LL minPower;
    if(y == 0)
        return 0;
    if(x == y){
        minPower = 2 * (x + y);
    }else if(x < y){
        LL temp = x;
        x = y;
        y = temp;
    }
    minPower = (x / y) * 4 * y + spendPower(y , x % y);
    return minPower;
}


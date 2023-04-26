#include<stdio.h>
#define ull unsigned long long

int main(){
    ull x, y;
    scanf("%llu %llu", &x, &y);
    ull res = 0;
    while (y!=0){
        res += (x/y)*y*4;
        x %= y;
        ull temp = x;
        x = y;
        y = temp;
    }
    printf("%llu\n", res);
    return 0;
}

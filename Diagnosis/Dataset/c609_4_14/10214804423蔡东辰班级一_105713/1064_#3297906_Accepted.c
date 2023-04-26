#include <stdio.h>
void swap(long long* a, long long* b){
    if(*a < *b){
        long long temp = *b;
        *b = *a;
        *a = temp;
    }
}
int main(){
    long long x, y, big, small;
    scanf("%lld %lld", &x, &y);
    big = (x>y)? x : y;
    small = (x>y)? y : x;
    long long result = 0;
    if(x == y){
        printf("%lld", 4*x);
    }
    else{
        while(big != small && big>0){//余数为0时说明刚好分完
            swap(&big, &small);
            long long m = big / small;
            result += 4 * small*m;//用减法会超时
            big = big % small;
        }
        result += 4*big;
        printf("%lld", result);
    }
    return 0;
}

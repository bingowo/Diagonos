#include <stdio.h>
void swap(int* a, int* b){
    if(*a < *b){
        int temp = *b;
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
        while(big != small){
            swap(&big, &small);
            result += 4 * small;
            big -= small;
        }
        result += 4*big;
        printf("%lld", result);
    }
    return 0;
}
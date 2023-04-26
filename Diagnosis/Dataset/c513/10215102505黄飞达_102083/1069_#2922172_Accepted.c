#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int reverse(int n){
    int res = 0;
    while (n){
        res *= 10;
        res += n%10;
        n /= 10;
    }
    return res;
}

int main(){
    int n = 0, m = 0, count = 1;
    scanf("%d ", &n);
    m = reverse(n);
    n += m;
    while (n != reverse(n)){
        m= reverse(n);
        n += m;
        count++;
    }
    printf("%d %d\n", count, n);
    return 0;
}
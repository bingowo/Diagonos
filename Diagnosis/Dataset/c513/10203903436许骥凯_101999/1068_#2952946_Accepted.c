#include<stdio.h>

int f[32] = {1}; int len = 1;
int fac(int n){
    if (n < len) return f[n];
    for (; len <= n; len++)
        f[len] = f[len-1] * 2;
    return f[n];
}

int cal(int m, int n){
    if (m == n) return 1;
    if (m > n) return 0;
    return 2 * cal(m, n-1) + fac(n - m - 1) - cal(m, n - m - 1);
}
int main(){
    int n, m;
    while(1){
        scanf("%d%d", &n, &m);
        if (n == -1 && m == -1) break;
        printf("%d\n", cal(m, n));
    }
    return 0;
}
#include<stdio.h>

long long int cal(int n){
    long long int res[55] = {0, 0, 0, 1}; int len = 4;
    if (n + 3 < len) return res[n + 3];
    for (; len <= n + 3; len++)
        res[len] = res[len-1] + res[len-2] + res[len-3] + res[len-4];
    return res[n + 3]; 
}
int main(){
    int n; scanf("%d", &n);
    for (int i = 0; i != n; i++){
        printf("case #%d:\n", i);
        int t; scanf("%d", &t);
        printf("%lld\n", cal(t));
    }
    return 0;
}
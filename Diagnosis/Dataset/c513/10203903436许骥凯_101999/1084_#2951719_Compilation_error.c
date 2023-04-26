#include<stdio.h>

void process(int n){
    int res[31] = {1}; int len = 1;
    if (n < len){
        printf("%d\n", res[n]);
        return;
    }
    for (; len <= n; len++)
        res[len] = res[len - 1] * 2;
    printf("%d\n", res[n]);
}
int main(){
    int n; scanf("%d", &n);
    for (int i = 0; i != n; i++){
        printf("case #%d:\n", i);
        int t; scanf("%d", &t);
        proecss(t);
    }
    return 0;
}
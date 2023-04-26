#include<stdio.h>

int cal(int n){
    if (n == 1) return 2;
    if (n == 2) return 4;
    if (n == 3) return 7;
    return 2 * cal(n-1) - cal(n-2) + cal(n-3);
}

int main(){
    while(1){    
        int t; scanf("%d", &t);
        if (t == -1) break;
        printf("%d\n", cal(t));
    }
    return 0;
}
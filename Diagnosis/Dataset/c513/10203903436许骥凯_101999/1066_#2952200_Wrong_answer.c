#include<stdio.h>

int pro(int n, int p, int m, int t){
    if (m == 1){
        if (p + 1 == t || p - 1 == t) return 1;
        return 0;
    }
    if (p == n) return pro(n, p - 1, m - 1, t);
    if (p == 1) return pro(n, p + 1, m - 1, t);
    return pro(n, p + 1, m - 1, t) + pro(n, p - 1, m - 1, t);
}


int main(){
    int n; scanf("%d", &n);
    for (int i = 0; i != n; i++){
        int n, p, m, t; scanf("%d%d%d%d", &n, &p, &m, &t);
        printf("%d\n", pro(n, p, m, t));
    }
    return 0;
}
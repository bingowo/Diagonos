#include<stdio.h>

int up(int a, int b, int x){
    if (x == 1) return a;
    if (x == 2) return b;
    return up(a, b, x - 1) + up(a, b, x - 2); 
}

int process(int a, int b, int n, int x){
    if (x == 1) return a;
    if (x == 2) return a;
    return process(a, b, n, x-1) + up(a, b, x-2);

}
int main(){
    int a, n, m, x;
    scanf("%d%d%d%d", &a, &n, &m, &x);
    
    int b;
    for (int i = 0; i <= m; i++)
        if (process(a, i, n, n - 1) == m)
            b = i;
    printf("%d\n", process(a, b, n, x));
    return 0;
}
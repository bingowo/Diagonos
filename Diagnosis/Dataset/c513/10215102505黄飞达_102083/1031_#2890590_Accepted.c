#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp(const void*a, const void*b){
    int x = *(int*)a;
    int y = *(int*)b;
    return x < y ? -1 : 1;
}

int main(){
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++){
        int n;
        scanf("%d ", &n);
        int a[1005] = {0}, b[1005] = {0};
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        for (int i = 0; i < n; i++) scanf("%d", &b[i]);
        qsort(a, n, sizeof(int), cmp);
        qsort(b, n, sizeof(int), cmp);
        long long res = 0;
        for (int i = 0; i < n; i++){
            res += a[i]*b[n-i-1];
        }
        printf("case #%d:\n%lld\n", t, res);        
    }

    return 0;
}

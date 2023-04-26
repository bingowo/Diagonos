#include<stdio.h>
#include<stdlib.h>

int cmp(const void *p1, const void *p2){
    return *(int *)p1 - *(int *)p2;
}

int cmp_r(const void *p1, const void *p2){
    return cmp(p2, p1);
}

int main(){
    int T; scanf("%d", &T);
    for (int i = 0; i != T; ++i){
        int n; scanf("%d", &n);
        int a[1000], b[1000];
        for (int j = 0; j != n; ++j) scanf("%d", &a[j]);
        for (int j = 0; j != n; ++j) scanf("%d", &b[j]);
        qsort(a, n, sizeof(a[0]), cmp);
        qsort(b, n, sizeof(b[0]), cmp_r);
        int res = 0;
        for (int j = 0; j != n; ++j)
            res += a[j] * b[j];
        printf("case #%d:\n%d\n", i, res); 
    }
    return 0;
}
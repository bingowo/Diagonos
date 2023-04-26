#include<stdio.h>
#include<stdlib.h>


int cal(int a){
    int cnt = 0;
    for (int i = 0; i != 64; i++){
        if (a & 1) cnt++;
        a >>= 1;
    }
    return cnt;
}

int cmp(const void *p1, const void *p2){
    int a1 = *(int *)p1, a2 = *(int *)p2;
    int cnt1 = cal(a1), cnt2 = cal(a2);
    if (cnt1 == cnt2) return a1 - a2;
    return cnt2 - cnt1;
}


int main(){
    int T; scanf("%d", &T);
    for (int i = 0; i != T; i++){
        printf("case #%d:\n", i);
        int n, arr[10000]; scanf("%d", &n);
        for (int i = 0; i != n; i++) scanf("%d", &arr[i]);
        qsort(arr, n, sizeof(int), cmp);
        for (int i = 0; i != n; i++) printf("%d%c", arr[i], i == n - 1? '\n': ' ' );
    }
    return 0;
}
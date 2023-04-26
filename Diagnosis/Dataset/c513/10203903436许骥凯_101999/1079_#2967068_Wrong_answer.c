#include<stdio.h>
#include<stdlib.h>


long long int Sum(int *t, int lo, int len){
    long long int res = 0;
    for (int i = 0; i != len; i++)
        res += t[lo + i];
    return res;
}

int cmp(const void *p1, const void *p2){
    return *(long long int*)p1 > *(long long int*)p2? 1: -1;
}

int main(){
    int pro; scanf("%d", &pro);
    for (int i = 0; i != pro; i++){
        printf("case #%d:\n", i);
        int n, m; scanf("%d%d", &n, &m);
        int temp[1003], index = 0; 
        for (int j = 0; j != n; j++)    
            scanf("%d", &temp[index++]);
        long long int* res = (long long int*)malloc(sizeof(long long int) * ((n + 1) * n / 2));
        int rlen = 0;
        for (int j = 0; j != index; j++)
            for (int k = 1; k <= index - j; k++)
                res[rlen++] = Sum(temp, j, k);
        qsort(res, rlen, sizeof(res[0]), cmp);
        for (int j = 0; j != m; j++){
            int L, U; scanf("%d%d", &L, &U);
            printf("%lld\n", Sum(res, L - 1, U - L + 1));
        }
        free(res);
    }
    return 0;
}
#include<stdio.h>
#include<stdlib.h>


int Sum(int *t, int lo, int len){
    int res = 0;
    for (int i = 0; i != len; i++)
        res += t[lo + i];
    return res;
}

int cmp(const void *p1, const void *p2){
    return *(int*)p1 - *(int*)p2;
}

int main(){
    int pro; scanf("%d", &pro);
    for (int i = 0; i != pro; i++){
        printf("case #%d:\n", i);
        int n, m; scanf("%d%d", &n, &m);
        int temp[1003], index = 0; 
        for (int j = 0; j != n; j++)    
            scanf("%d", &temp[index++]);
        int* res = (int*)malloc(sizeof(int) * ((n + 1) * n / 2));
        int rlen = 0;
        for (int j = 0; j != index; j++)
            for (int k = 1; k <= index - j; k++)
                res[rlen++] = Sum(temp, j, k);
        qsort(res, rlen, sizeof(res[0]), cmp);
        for (int j = 0; j != m; j++){
            int L, U; scanf("%d%d", &L, &U);
            printf("%d\n", Sum(res, L - 1, U - L + 1));
        }
    }
}
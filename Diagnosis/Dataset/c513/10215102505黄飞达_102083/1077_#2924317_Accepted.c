#include<stdio.h>
#include<stdlib.h>

int value[1001] = {0};

int cmp1(const void*a, const void* b){
    int x = *(int*)a, y = *(int*)b;
    return value[x] < value[y] ? -1 : 1;
    // if (value[x]!=0&&value[y]!=0) return value[x] < value[y] ? -1 : 1;
    // else return x < y ? -1 : 1;
}

int cmp2(const void*a, const void* b){
    int x = *(int*)a, y = *(int*)b;
    return x < y ? -1 : 1;
}

int main(){
    int m, n;
    scanf("%d", &m);
    int B1[505] = {0}, B2[505] = {0};
    for (int i = 1; i <= m; i++) {
        int temp = 0;
        scanf("%d", &temp);
        value[temp] = i;
    }
    scanf("%d", &n);
    int i1 = 0, i2 = 0;
    for (int i = 0; i < n; i++) {
        int temp = 0;
        scanf("%d", &temp);
        if (value[temp] != 0) B1[i1++] = temp;
        else B2[i2++] = temp;
    }
    qsort(B1, i1, sizeof(int), cmp1);
    qsort(B2, i2, sizeof(int), cmp2);
    for (int i = 0; i < i1; i++) printf("%d ", B1[i]);
    for (int i = 0; i < i2; i++) printf("%d ", B2[i]);
    printf("\n");
    return 0;
}
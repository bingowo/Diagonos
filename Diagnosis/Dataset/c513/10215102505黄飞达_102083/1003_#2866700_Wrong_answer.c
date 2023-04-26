#include<stdio.h>
#include<stdlib.h>

int func(long long num){
    int count = 0;
    long long yi = 1;
    for (int i = 0; i < 64; i++) {
        count += (yi & num);
        num >>= 1;
    }
    return count;
}

int cmp(const void* a, const void* b){
    int counta = func(*(long long*)a);
    int countb = func(*(long long*)b);
    if (counta != countb){
        return countb - counta;
    }
    else{
        return *(long long*)a - *(long long*)b;
    }
}

int main(){
    int t, n;
    scanf("%d", &t);
    for (int i = 0; i < t; i++){
        scanf("%d", &n);
        long long arr[10005] = {0};
        for (int j = 0; j < n; j++){
            scanf("%lld", &arr[j]);
        }
        qsort(arr, n, sizeof(long long), cmp);
        printf("case #%d:\n", i);
        for (int j = 0; j < n; j++){
            printf("%lld ", arr[j]);
//printf("count:%d\n", func(arr[j]));
        } 
        printf("\n");
    }
    return 0;
}

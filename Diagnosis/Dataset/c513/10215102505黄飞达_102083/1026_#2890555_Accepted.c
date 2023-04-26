#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp(const void*a, const void*b){
    int x = *(int*)a;
    int y = *(int*)b;
    return x < y ? -1 : 1;
}

int main(){
    int n;
    scanf("%d ", &n);
    int arr[100005] = {0};
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), cmp);
    long long res = 0;
    for (int i = 0; i < n; i+=2){
        res += abs(arr[i] - arr[i+1]);
    }
    printf("%lld\n", res);
    return 0;
}

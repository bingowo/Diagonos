#include<stdio.h>
#include<stdlib.h>

long long arr[1000000] = {0};

int cmp(const void*a, const void*b){
    long long x = *(long long*)a;
    long long y = *(long long*)b;
    return x > y ? -1 : 1;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++){
        scanf("%lld", &arr[i]);
    }
    qsort(arr, n, sizeof(long long), cmp);
    long long res = 0;
    for (int i = 0; i < m; i++){
        res += arr[0] - arr[i];
    }
    for (int i = 0; i < n - m; i++){
        long long change = m*arr[i+1] - (m-1)*arr[i] - arr[i+m];
        if (change < 0) res += change;
        
    }
    printf("%lld\n", res);
    return 0;


}
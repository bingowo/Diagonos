#include<stdio.h>
#include<stdlib.h>

long long arr[1000000] = {0};

int cmp(const void*a, const void*b){
    long long x = *(long long*)a;
    long long y = *(long long*)b;
    return x > y ? -1 : 1;
}

int main(){
    long long n, m;
    scanf("%lld %lld", &n, &m);
    for (int i = 0; i < n; i++){
        scanf("%lld", &arr[i]);
    }
    qsort(arr, n, sizeof(long long), cmp);
    long long res = 0;
    for (int i = 0; i < m; i++){
        res += arr[0] - arr[i];
    }
    long long tempres = res;
    for (int i = 0; i < n - m; i++){
        long long change = (1-m)*arr[i] + m*arr[i+1] - arr[i+m];
        tempres += change;
        if (res > tempres) res = tempres;
    }
    printf("%lld\n", res);
    return 0;


}
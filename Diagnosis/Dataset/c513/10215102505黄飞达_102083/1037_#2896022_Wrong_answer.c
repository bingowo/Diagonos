#include<stdio.h>
#include<stdlib.h>

int arr[1000000] = {0};

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    long long res = 0, tempres = 0;
    for (int i = 0; i < m; i++){
        res += arr[0] - arr[i];
    }
    for (int i = 1; i <= n - m; i++){
        for (int j = 0; j < m; j++){
            tempres += arr[i] - arr[i+j];
        }
        if (res > tempres) res = tempres;
    }
    printf("%lld\n", res);
    return 0;


}
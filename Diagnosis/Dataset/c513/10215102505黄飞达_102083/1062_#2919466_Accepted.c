#include<stdio.h>

int main(){
    long long arr[50] = {0};
    arr[1] = 1, arr[2] = 2, arr[3] = 4, arr[4] = 8;
    for (int i = 5; i <= 50; i++) arr[i] = arr[i-1]+arr[i-2]+arr[i-3]+arr[i-4];
    int T;
    scanf("%d ", &T);
    for (int t = 0; t < T; t++){
        printf("case #%d:\n", t);
        int n;
        scanf("%d", &n);
        printf("%lld\n", arr[n]);
    }
    return 0;
}
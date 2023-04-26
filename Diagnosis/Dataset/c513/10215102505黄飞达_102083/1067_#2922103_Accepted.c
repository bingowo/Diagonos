#include<stdio.h>
#include<stdlib.h>
#define ull long long

int main(){
    int T;
    scanf("%d ", &T);
    ull arr[75] = {0,1,1};
    for (int i = 3; i < 75; i++){
        arr[i] = arr[i-1]+arr[i-2]+arr[i-3];
    }
    for (int t = 0; t < T; t++){
        int n;
        scanf("%d ", &n);
        printf("case #%d:\n%llu\n", t, arr[n]);
    }
    return 0;
}
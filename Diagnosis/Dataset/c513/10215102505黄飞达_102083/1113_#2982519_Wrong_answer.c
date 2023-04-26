#include<stdio.h>

int main(){
    int k, n;
    scanf("%d %d", &k, &n);
    long long arr[115]={0};
    arr[11]=1;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=k; j++){
            arr[9+i]+=arr[9+i-j];
        }
    }
    printf("%lld\n", arr[9+n]);
    return 0;
}
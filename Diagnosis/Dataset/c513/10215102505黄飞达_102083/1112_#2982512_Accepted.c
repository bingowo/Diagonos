#include<stdio.h>

int main(){
    int T;
    scanf("%d", &T);
    for (int t=0; t<T; t++){
        // printf("case #%d:\n", t);
        int n;
        scanf("%d", &n);
        long long count=0;
        for (int i=0;i<=n/4;i++){
            for (int j=0;j<=n/3;j++){
                for (int k=0;k<=n/2;k++){
                    if (i*4+j*3+k*2<=n) count++;
                    else break;
                }
            }
        }
        printf("%lld\n", count);
    }
    return 0;
}
#include <stdio.h>
#include <math.h>
#define N 1001
int makeP[N];
int Prime[N];
long long ans[N];
long long max(long long a, long long b){
    return a>b?a:b;
}
//int isPrime(int x){
//    if(x<2) return 0;
//    int c = (int)(sqrt(x)+0.5);
//    for(int i = 2; i<=c; i++){
//        if(x%i==0) return 0;
//    }
//    return 1;
//}
int main(){
    int n; scanf("%d",&n);
    for(int i = 2,j = 0; i<N; i++){
        if(!makeP[i]){
            Prime[j++] = i;
            for(int k = i*i; k<N; k+=i) makeP[k] = 1;
        }
    }
//    for(int i = 0; i<j; i++){
//        if(!isPrime(Prime[i])) printf("no ");
////        printf("%d ",Prime[i]);
//    }
//    printf("done");
//    printf("%d", isPrime(n));
    ans[0] = 1;
    for(int i = 0; Prime[i]<=n; i++){
        for(int j = Prime[i]; j<=n; j++){
            ans[j] += ans[j-Prime[i]];
        }
    }
    printf("%lld",ans[n]);
    return 0;
}
//2+7
//2+2+5
//2+2+2+3
//3+3+3
//3+7
//5+5
//3+2+5
//3+2+2+3
//2+2+2+2+2
//11
//2+2+7
//3+3+5
//2+2+2+5
//3+3+3+2
//2+2+2+2+3
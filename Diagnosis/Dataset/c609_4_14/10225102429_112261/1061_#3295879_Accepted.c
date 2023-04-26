#include <stdio.h>
#define N 1001
int makeP[N];
int Prime[N];
long long ans[N];
long long max(long long a, long long b){
    return a>b?a:b;
}
int main(){
    int n; scanf("%d",&n);
    int num = 0;
    for(int i = 2; i<N; i++){
        if(!makeP[i]){
            Prime[num++] = i;
            for(int k = i*i; k<N; k+=i) makeP[k] = 1;
        }
    }
    ans[0] = 1;
    for(int i = 0; i<num&&Prime[i]<=n; i++){
        for(int j = Prime[i]; j<=n; j++){
            ans[j] += ans[j-Prime[i]];
        }
    }
    printf("%lld",ans[n]);
    return 0;
}
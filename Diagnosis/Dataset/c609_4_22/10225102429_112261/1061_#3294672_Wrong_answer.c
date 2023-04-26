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
    for(int i = 2,j = 0; i<N; i++){
        if(!makeP[i]){
            Prime[j++] = i;
            for(int k = i*i; k<N; k+=i) makeP[k] = 1;
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = Prime[i]; j<=n; j++){
            ans[j] = max(ans[j-Prime[i]]+1,ans[j]);
        }
    }
    printf("%lld",ans[n]);
    return 0;
}
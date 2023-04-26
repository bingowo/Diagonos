#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long count(int n,int* primes){
    static long long ans[5000] = {0};
    if(!ans[n]){
        int i;
        if(!n) return ans[n] = 1;
        for(i = 0; primes[i] <= n;i++){
            ans[n] += count(n - primes[i],primes);
        }
    }
    return ans[n];
}

int main(){
    int T;
    scanf("%d",&T);
    int primes[51];
    for(int i = 0; i < 50;i++)
    {
        primes[i] = i + 1;
    }
    for(int i = 0; i < T; i++){
        int n;
        scanf("%d",&n);
        printf("%lld",count(n,primes));
    }
}

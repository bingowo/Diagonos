#include <stdio.h>
#include <stdlib.h>

long long consume(long long L,long long W){
    long long max = L >= W ? L : W;
    long long min = L >= W ? W : L;
    long long bian = min;
    if(bian == 0){
        return 0;
    }
    long long n = max / min;
    long long ans = 0;
    ans = 4*bian*n + consume(min,max % min);
    return ans;
}

int main(){
    long long L;
    long long W;
    scanf("%lld %lld",&L,&W);
    printf("%lld",consume(L,W));
}

#include <stdio.h>
#include <stdlib.h>

long long consume(int L,int W){
    int max = L >= W ? L : W;
    int min = L >= W ? W : L;
    int bian = min;
    if(bian == 0){
        return 0;
    }
    int n = max / min;
    long long ans = 0;
    ans = 4*bian*n + consume(min,max % min);
    return ans;
}

int main(){
    int L;
    int W;
    scanf("%d %d",&L,&W);
    printf("%lld",consume(L,W));
}

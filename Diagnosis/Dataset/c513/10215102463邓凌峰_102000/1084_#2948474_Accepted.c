#include <stdio.h>
#include <stdlib.h>


int main(){
    int T;scanf("%d",&T);
    for(int i=0;i<T;i++){
        int N;scanf("%d",&N);
        long long ans=1;
        for(int i=1;i<=N;i++){
            ans*=2;
        }
        printf("case #%d:\n%lld\n",i,ans);
    }
}

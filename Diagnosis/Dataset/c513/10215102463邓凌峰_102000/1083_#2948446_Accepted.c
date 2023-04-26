#include <stdio.h>
#include <stdlib.h>


int main(){
    int T;scanf("%d",&T);
    for(int i=0;i<T;i++){
        int N;scanf("%d",&N);
        int cnt=0;
        for(int i=5;i<=N;i*=5){
            cnt+=N/i;
        }
        printf("case #%d:\n%d\n",i,cnt);

    }
}

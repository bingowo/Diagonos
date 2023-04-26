#include <stdio.h>
#include <math.h>
int main(){
    int T,N;
    scanf("%d\n",&T);
    for(int t=0;t<T;t++){
        scanf("%d\n",&N);
        printf("case #%d:\n",t);
        printf("%lld\n",pow(2.0,N));
    }
    return 0;
}
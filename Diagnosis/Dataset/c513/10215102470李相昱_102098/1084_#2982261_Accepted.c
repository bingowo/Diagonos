#include <stdio.h>
int main() {
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int N;
        scanf("%d",&N);
        long long int ret=1;
        printf("case #%d:\n",i);
        printf("%lld\n",ret<<N);
    }
    return 0;
}

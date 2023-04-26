#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,i,j,k;
    scanf("%d",&T);
    long long n[T];
    long long x[T];
    for(i=0;i<T;i++){
        j=0;
        scanf("%lld",&n[i]);
        while(n[i]){
            x[j++]=n[i]%2333;
            n[i]/=2333;
        }
        for(k=j-1;k>=0;k--){
            printf("%lld ",x[k]);
        }
        printf("\n");
}
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,i,j,k;
    scanf("%d",&T);
    long long n[T];
    long long x[T][6];
    int b[100];
    for(i=0;i<T;i++)
        scanf("%lld",&n[i]);
    for(j=0;j<T;j++){
        k=0;
        while(n[j]){
            x[j][k++]=n[j]%2333;
            n[j]/=2333;
            b[j]=k-1;
        }
    }
    for(i=0;i<T;i++){
        for(j=b[i];j>=0;j--){
            printf("%lld ",x[i][j]);
        }
        printf("\n");
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
int cmp1(const void*a, const void*b){
    return *(int*)a-*(int*)b;
}
int main(){
    int n;
    scanf("%d", &n);
    long long *num, sum=0;
    num = (long long*)malloc(sizeof(long long)*n);
    for(int i=0; i<n; i++){
        scanf("%lld", &num[i]);
    }
    qsort(num,n,sizeof(num[0]),cmp1);
    for(int i=0; i<n/2; i++){
        sum += num[2*i+1]-num[2*i];
    }
    printf("%lld", sum);
    free(num);
    return 0;
}

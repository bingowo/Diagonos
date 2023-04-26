#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b){
    return *(long long int*)a>*(long long int*)b;
}

int main(){
    long long int n;
    scanf("%lld",&n);
    long long int a[n];
    for(int i=0;i<n;i++){
        printf("%lld",&a[i]);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    long long int sum=0;
    for(int i=0;i<(n/2);i++){
        sum=sum+a[2*i+1]-a[2*i];
    }
    printf("%lld",sum);
    return 0;
}
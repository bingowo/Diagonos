#include <stdio.h>
#include <stdlib.h>

int cmp1(const void *a , const void *b){
    return *(int *)a - *(int *)b;
}

int main(){
    long long int n;
    scanf("%lld\n",&n);
    long long int s[n];
    long long i=0;
    while(scanf("%lld",&s[i])!=0) i++;
    qsort(s,n,sizeof(s[0]),cmp1);
    long long int p=0;
    for(i=0;i<(n/2);i=i+2){
        p=p+abs(s[i]-s[i+1]);
    }
    printf("%lld",p);
    return 0;
}
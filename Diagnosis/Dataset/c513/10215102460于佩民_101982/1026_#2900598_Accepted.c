#include <stdio.h>
#include <stdlib.h>

long long int num[100000];
long long int cmp(const void*a,const void*b){
    long long int m,n;
    m=*(long long int*)a;
    n=*(long long int*)b;
    return m-n;
}

int main(){
    int count,i=0,now;
    long long int sum=0;
    scanf("%d",&count);
    while(i<count){
        scanf("%lld",&num[i]);
        i++;
    }
    qsort(num, count, sizeof(long long int), cmp);
    for(now=1;now<=count-1;now+=2){
        sum+=(num[now]-num[now-1]);
    }
    printf("%lld",sum);
    return 0;
}
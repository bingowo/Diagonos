#include <stdio.h>
#include <stdlib.h>

long long int num[100000];
int cmp(const void*a,const void*b){
    int m,n;
    m=*(int*)a;
    n=*(int*)b;
    return m-n;
}

int main(){
    int count,i=0,now;
    long long int sum=0;
    scanf("%d",&count);
    while(i<count){
        scanf("%lld",num[i]);
        i++;
    }
    qsort(num, count, sizeof(int), cmp);
    for(now=2;now<=count;now+=2){
        sum+=num[now]-num[now-1];
    }
    printf("%lld",sum);
    return 0;
}
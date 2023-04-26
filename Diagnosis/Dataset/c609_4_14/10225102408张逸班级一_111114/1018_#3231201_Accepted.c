#include<stdio.h>
#include<stdlib.h>
int cmp(const void* a1,const void*a2){
    if(*(long long*)a1>*(long long*)a2){
        return 1;
    }
    else return -1;
}
int main(){
    int a;
    scanf("%d",&a);
    long long num[a];
    for(int i=0;i<a;i++){
        scanf("%lld",&num[i]);
    }
    qsort(num,a,sizeof(num[0]),cmp);
    long long sum=0;
    for(int i=0;i<=a-2;i+=2){
        sum+=(num[i+1]-num[i]);
    }
    printf("%lld",sum);
    return 0;
}
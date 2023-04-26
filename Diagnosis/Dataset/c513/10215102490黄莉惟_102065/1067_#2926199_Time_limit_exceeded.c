#include<stdio.h>
#include<string.h>
#include <stdlib.h>
long long int tribonacci(int n){
    if(n==0){
        return 0;
    }else if(n==1||n==2){
        return 1;
    }else{
        return tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
    }
}
int main(){
    int t,i,n;
    long long int sum;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d",&n);
        sum=tribonacci(n);
        printf("%lld",sum);
    }
}
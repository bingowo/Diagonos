#include<stdio.h>
#include<string.h>
#include <stdlib.h>
long long int tribonacci(int n){
    long long int s[100];
    if(n==0){
        return 0;
    }else if(n==1||n==2){
        return 1;
    }else{
       s[0]=0;
       s[1]=1;
       s[2]=1;
       for(i=3;i<=n;i++){
           s[i]=s[i-1]+s[i-2]+s[i-3];
       }
       return s[n-1];
    }
}
int main(){
    int t,i,n;
    long long int sum;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d",&n);
        printf("case #%d:\n",i);
        sum=tribonacci(n);
        printf("%lld\n",sum);
    }
}
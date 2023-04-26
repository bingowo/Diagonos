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
       for(int i=0;i<=n;i++){
           if(s[i]==0){
               for(int j=i-1;j>0;j--){
                   s[i]+=s[j];
                   s[i]++;
               }
           }
       }
       return s[n];
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
        printf("%lld",sum);
    }
}
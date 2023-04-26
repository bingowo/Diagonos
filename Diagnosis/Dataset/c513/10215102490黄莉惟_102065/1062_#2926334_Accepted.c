#include<stdio.h>
#include <stdlib.h>
#include<string.h>
long long int stair(int n){
    long long int s[100];
    int i;
    if(n==1){
        return 1;
    }else if(n==2){
        return 2;
    }else if(n==3){
        return 4;
    }else if(n==4){
        return 8;
    }else{
       s[0]=1;
       s[1]=2;
       s[2]=4;
       s[3]=8;
       for(i=4;i<=n;i++){
           s[i]=s[i-1]+s[i-2]+s[i-3]+s[i-4];
       }
       return s[n-1];
    }
    
}
int main(){
    int t,i,n;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d",&n);
        printf("case #%d:\n",i);
        printf("%lld\n",stair(n));
    }
}
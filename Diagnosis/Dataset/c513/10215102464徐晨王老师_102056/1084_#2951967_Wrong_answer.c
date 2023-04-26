#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void multi(int* list,int ans){
    for(int i=99;list[i]!=0;i--){
        list[i]=list[i]*ans;

    }
    for(int i=98;;i--){

        list[i]=list[i+1]/10+list[i];
        list[i+1]=list[i+1]%10;
        if(list[i]==0)break;
    }
}

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
    int n;
    scanf("%d",&n);
    printf("case #%d:\n",t);
    int sum[100];
    sum[99]=1;
    for(int i=0;i<99;i++){
        sum[i]=0;
    }
    for(int i=0;i<n;i++){
        multi(sum,2);
    }
    int j=0;
    for(;j<100;j++){
        if(sum[j]!=0)break;
    }
    for(;j<100;j++){
    printf("%d",sum[j]);}
    }
    printf("\n");
    return 0;
}
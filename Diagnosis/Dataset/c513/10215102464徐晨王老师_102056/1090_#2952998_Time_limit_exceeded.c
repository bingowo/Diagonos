#include <stdio.h>
#include <string.h>

void multi(long long int* list,int ans){
    int lens;
    for(int i=0;i<1000;i++){
        list[i]=list[i]*ans;
        if(list[i]!=0)lens=i;
    }
    for(int i=998;;i--){
        list[i]=list[i+1]/10+list[i];
        list[i+1]=list[i+1]%10;
        if(i==(lens-1))break;
    }
}

int main(){
    int N;
    scanf("%d",&N);
    while(N){
    long long int sum[1000];
    sum[999]=N;
    for(int i=0;i<999;i++){
        sum[i]=0;
    }

    for(int i=1;i<N+1;i++){
        multi(sum,i);
    }
    int j=0;
    for(;j<1000;j++){
        if(sum[j]!=0){
            printf("%d",sum[j]);
            break;}
    }
    scanf("%d",&N);
    }

    return 0;
}
#include <stdio.h>
#include <string.h>

void multi(int* list,int ans){
    int lens;
    for(int i=0;i<10000;i++){
        list[i]=list[i]*ans;
        if(list[i]!=0)lens=i;
    }
    for(int i=9998;;i--){
        list[i]=list[i+1]/10+list[i];
        list[i+1]=list[i+1]%10;
        if(i==(lens-1))break;
    }
}

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
    int sum[10000];
    sum[9999]=1;
    for(int i=0;i<9999;i++){
        sum[i]=0;
    }
    int N;
    scanf("%d",&N);
    for(int i=1;i<N+1;i++){
        multi(sum,i);
    }
    int j=0;
    for(;j<10000;j++){
        if(sum[j]!=0)break;
    }
    printf("case #%d:\n",t);
    int ze=0;
    for(;j<10000;j++){
    if(sum[j]==0)ze=ze+1;}
    printf("%d\n",ze);
    }
    
    return 0;
}
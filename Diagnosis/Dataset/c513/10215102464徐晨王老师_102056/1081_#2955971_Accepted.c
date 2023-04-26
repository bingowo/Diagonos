#include <stdio.h>
#include <string.h>

void multi(int* list,int ans){
    for(int i=999;;i--){
        list[i]=list[i]*ans;
        if(list[i]==0&&list[i-1]==0&&list[i-2]==0&&list[i-3]==0&&list[i-4]==0&&list[i-5]==0&&list[i-6]==0)break;

    }
    for(int i=998;;i--){

        list[i]=list[i+1]/10+list[i];
        list[i+1]=list[i+1]%10;
        if(list[i]==0&&list[i-1]==0&&list[i-2]==0&&list[i-3]==0&&list[i-4]==0&&list[i-5]==0&&list[i-6]==0)break;
    }
}

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
    int a,n;
    scanf("%d%d",&a,&n);
    int sum[1000];
    sum[999]=1;
    for(int i=0;i<999;i++){
        sum[i]=0;
    }
    for(int i=1;i<n+1;i++){
        multi(sum,a);
    }
    printf("case #%d:\n",t);
    int j=0;
    for(;j<1000;j++){
        if(sum[j]!=0)break;
    }
    for(;j<1000;j++){
    printf("%d",sum[j]);}
    printf("\n");
    }
    
    return 0;
}
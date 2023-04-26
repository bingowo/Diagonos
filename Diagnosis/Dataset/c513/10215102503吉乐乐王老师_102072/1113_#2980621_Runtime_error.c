#include<stdio.h>
#include<stdlib.h>
#define N 30
typedef unsigned long long int ull;
void add(int num1[],int num2[]){
    for(int i=N-1;i>0;i--){
        num2[i]+=num1[i];
        num2[i-1]+=num2[i]/10;
        num2[i]%=10;
    }
}
int main(){
    int k,n;
    scanf("%d%d",&k,&n);
    int num[101][N]={0};
    num[0][N-1]=0;num[1][N-1]=1;
    for(int i=2;i<k;i++){
        num[i][N-1]=0;
        for(int j=0;j<i;j++){
            add(num[j],num[i]);
        }
    }
    for(int i=k;i<n;i++){
        num[i][N-1]=0;
        for(int j=i-k;j<i;j++){
            add(num[j],num[i]);
        }
    }
    int idx=0;
    while(num[n-1][idx]==0&&idx<N)idx++;
    if(idx==N)printf("0");
    else{
        for(int i=idx;i<N;i++){
            printf("%d",num[n-1][i]);
        }
    }
}
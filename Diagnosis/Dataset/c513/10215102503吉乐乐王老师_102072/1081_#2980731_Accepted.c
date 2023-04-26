#include<stdio.h>
#include<stdlib.h>
#define N 1000
int main(){
    int t;
    scanf("%d",&t);getchar();
    int cas=0;
    while(t--){
        int arr[N]={0};
        int a,n;
        scanf("%d %d",&a,&n);getchar();
        if(n==0){printf("case #%d:\n1\n",cas++);continue;}
        arr[N-1]=1;
        for(int i=1;i<=n;i++){
            for(int k=N-1;k>0;k--)arr[k]*=a;
            for(int k=N-1;k>0;k--){
                arr[k-1]+=arr[k]/10;
                arr[k]%=10;
            }
        }
        printf("case #%d:\n",cas++);
        int idx=0;
        while(arr[idx]==0)idx++;
        while(idx<N){
            printf("%d",arr[idx]);idx++;
        }
        printf("\n");
    }
}
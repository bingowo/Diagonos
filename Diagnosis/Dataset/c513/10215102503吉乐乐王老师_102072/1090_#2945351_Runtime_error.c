#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define N 1000000000
int main(){
    long long int n;
    while(scanf("%lld",&n)==1&&n!=0){
        long long int arr[N]={0};
        arr[N-1]=1;
        for(int i=1;i<=n;i++){
            for(int k=N-1;k>0;k--)arr[k]*=n;
            for(int k=N-1;k>0;k--){
                arr[k-1]+=arr[k]/10;
                arr[k]%=10;
            }
        }
        int idx=0;
        while(arr[idx]==0)idx++;
        printf("%lld\n",arr[idx]);
    }
}
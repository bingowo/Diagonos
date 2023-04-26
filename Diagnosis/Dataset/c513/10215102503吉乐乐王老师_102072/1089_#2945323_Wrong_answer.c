#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define N 10000
int main(){
    int t;
    scanf("%d",&t);getchar();
    int cas=0;
    while(t--){
        unsigned long long int arr[N]={0};
        unsigned long long int a,b,n;
        scanf("%llu%llu%llu",&a,&b,&n);getchar();
        arr[N-1]=a;
        for(int i=2;i<=b;i++){
            for(int k=N-1;k>0;k--)arr[k]*=a;
            for(int k=N-1;k>0;k--){
                arr[k-1]+=arr[k]/10;
                arr[k]%=10;
            }
        }
        printf("case #%d:\n",cas++);
        int idx=0;
        for(int i=N-n;i<N;i++){
            printf("%llu",arr[i]);
        }
        printf("\n");
    }
}
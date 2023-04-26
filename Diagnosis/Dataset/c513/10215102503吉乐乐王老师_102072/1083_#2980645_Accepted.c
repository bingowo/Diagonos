#include<stdio.h>
#include<stdlib.h>
#define N 1000
int main(){
    int t;
    scanf("%d",&t);getchar();
    int cas=0;
    while(t--){
        // int arr[N]={0};
        int n;
        scanf("%d",&n);getchar();
        printf("case #%d:\n%d\n",cas++,n/5+n/25+n/125+n/625);
        // if(n==0){printf("case #%d:\n1\n",cas++);continue;}
        // arr[N-1]=1;
        // for(int i=2;i<=n;i++){
        //     for(int k=N-1;k>0;k--)arr[k]*=i;
        //     for(int k=N-1;k>0;k--){
        //         arr[k-1]+=arr[k]/10;
        //         arr[k]%=10;
        //     }
        // }
        // printf("case #%d:\n",cas++);
        // int cnt=0;
        // for(int i=N-1;i>0;i--){
        //     if(arr[i]!=0)break;
        //     cnt++;
        // }
        // printf("%d\n",cnt);
    }
}
#include<stdio.h>
#include<string.h>
#define MAX  100000

int arr[MAX]={0};

void multi(int N){
    int len=0;
    while(arr[len]!=-1) len++;
    for (int i=0; i<len; i++) arr[i]*=N;
    for (int i=0; i<len; i++){
        if (arr[i]>=10){
            if (arr[i+1]==-1) arr[i+1]=0;
            arr[i+1]+=arr[i]/10;
            arr[i]%=10;
        }
    }
    return;
}

int main(){
    int T;
    scanf("%d ",&T);
    for (int t=0; t<T; t++){
        int N;
        scanf("%d", &N);
        printf("case #%d:\n", t);
        for (int i=0; i<MAX; i++) arr[i]=-1;
        arr[0]=1;
        while (N){
            multi(N);
            N--;
        }
        int res=0, index=0;
        for (int i=0; ;i++){
            if (arr[i]==0) res++;
            else break;
        }
        printf("%d\n", res);
    }
    return 0;
}
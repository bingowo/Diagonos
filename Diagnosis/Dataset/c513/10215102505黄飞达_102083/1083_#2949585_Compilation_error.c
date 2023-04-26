#include<stdio.h>
#include<string.h>
const int MAX = 1000;

int a[MAX];

void multi(int N){
    int len=0;
    while(a[len]!=-1) len++;
    for (int i=0; i<len; i++) a[i]*=N;
    for (int i=0; i<len; i++){
        if (a[i]>=10){
            if (a[i+1]==-1) a[i+1]=0;
            a[i+1]+=a[i]/10;
            a[i]%=10;
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
        for (int i=0; i<MAX; i++) a[i]=-1;
        a[0]=1;
        while (N){
            multi(N);
            N--;
        }
        int res=0, index=0;
        for (int i=0; ;i++){
            if (a[i]==0) res++;
            else break;
        }
        printf("%d\n", res);
    }
    return 0;
}
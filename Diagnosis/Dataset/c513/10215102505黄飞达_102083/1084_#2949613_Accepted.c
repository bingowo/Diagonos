#include<stdio.h>

int pow(int a, int b){
    int res = 1;
    for (int i=0; i<b; i++) res*=a;
    return res;
}

int main(){
    int T;
    scanf("%d",&T);
    for (int t=0; t<T; t++){
        int N;
        scanf("%d", &N);
        int num = pow(2, N);
        printf("case #%d:\n%d\n", t, num);   
    }
    return 0;
}
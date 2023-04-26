#include<stdio.h>
int main(){
    int T;
    long long N;
    int R;
    char *s="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    scanf("%d", &T);
    for(int i=0; i<T; i++){
        scanf("%lld %d", &N, &R);
        if(N<0){
            N = N*(-1);
            printf("%c", '-');
        }
        while(N!=0){
            printf("%c", s[N%R]);
            N /= R;
        }
        printf('\n');
    }
    return 0;
}
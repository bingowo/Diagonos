#include<stdio.h>
#include<stdlib.h>
int main(){
    int T;
    long long N;
    int R, count;
    char *s="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *temp;
    temp = malloc(sizeof(char)*33);
    scanf("%d", &T);
    for(int i=0; i<T; i++){
        scanf("%lld %d", &N, &R);
        count = 0;
        if(N<0){
            N = N*(-1);
            printf("%c", '-');
        }
        while(N!=0){
            temp[count] = s[N%R];
            N /= R;
            count++;
        }
        for(int i=0; i<count; i++){
            printf("%c", temp[count-i-1]);
        }
        printf("%c", '\n');
    }
    free(temp);
    return 0;
}
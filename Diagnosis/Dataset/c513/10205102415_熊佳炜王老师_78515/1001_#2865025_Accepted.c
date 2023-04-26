#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int T, R, N, i = 0, s = 1;
    char a[33];
    scanf("%d", &T);
    while(i < T){
        i++;
        scanf("%d %d", &N, &R);
        if(N < 0){
            s = 0;
            N = -N;
        }
        for(int j = 0; j < 33; j++){
             a[j] = '?';
        }
        int k;
        for(k = 0; N != 0; k++){
            int r = N % R;
            N /= R;
            if(r >= 10){
                a[k] = r + '7';
            }else{
                a[k] = r + '0';
            }
        }
        if(s == 0)a[k] = '-';
        int j;
        for(j = 32; j >= 0; j--){
            if(a[j] == '?')continue;
            printf("%c", a[j]);
        }
        printf("\n");
        s = 1;
    }
    
    return 0;
}
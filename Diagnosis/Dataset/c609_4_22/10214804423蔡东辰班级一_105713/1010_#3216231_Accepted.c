#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count(char c);
int GCD(int m, int n);
int main()
{
    char table[] = "0123456789ABCDEFGHIJ";
    int N, R, cnt = 0;
    char array[100];
    scanf("%d %d", &N, &R);
    if(N==0){
        printf("0");
        return 0;
    }
    while(N!=0){
        if(N%R < 0){
            array[cnt++] = table[N%R-R];
            N += R;
        }
        else{
            array[cnt++] = table[N%R];
        }
        N /= R;
    }
    for(int n = --cnt; n>=0; n--){
        printf("%c", array[n]);
    }
    return 0;
}

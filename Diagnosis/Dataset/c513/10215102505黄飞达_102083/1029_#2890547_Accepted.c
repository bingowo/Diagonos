#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cmp(const void*a, const void*b){
    char x = *(char*)a;
    char y = *(char*)b;
    return x < y ? -1 : 1;
}

int main(){
    int T;
    scanf("%d ", &T);
    for (int t = 0; t < T; t++){
        char in[201], out[201];
        gets(in);
        int len = strlen(in), outi = 0;
        for (int i = 0; i < len; i++){
            if ('A' <= in[i] && in[i] <= 'Z') {
                out[outi++] = in[i];
            }
        }
        qsort(out, outi, sizeof(char), cmp);
        outi = 0;
        for (int i = 0; i < len; i++){
            if ('A' <= in[i] && in[i] <= 'Z'){
                in[i] = out[outi++];
            }
        }  
        printf("case #%d:\n", t);
        for (int i = 0; i < len; i++) printf("%c", in[i]);
        printf("\n");

    }
    return 0;
}
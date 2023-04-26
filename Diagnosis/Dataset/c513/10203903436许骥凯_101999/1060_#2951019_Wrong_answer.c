#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main(){
    char s[101]; scanf("%s", s);
    int len = 0, tlen = 0;
    int slen = strlen(s);
    for (int i = 0; i != slen; i++){
        if (isdigit(s[i]) && (s[i] != '0' || len != 0)) tlen++;
        else{
            if (tlen > len) len = tlen;
            tlen = 0;
        }
    }
    printf("%d\n", len);
    return 0;
}
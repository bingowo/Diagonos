#include <stdio.h>
#include <string.h>

int func(char s[], int i){
    int used[128] = {0};
    for (int j = 0; i+j<strlen(s); j++){
        if (used[s[i+j]]==1) return j;
        else used[s[i+j]] = 1;
    }
    return strlen(s)-i;
}

int main(){
    char s[1000005] = {0};
    gets(s);
    int slen = strlen(s), maxlen = -1, pos = 0;
    int len_arr[1000005] = {0};
    for (int i = 0; i < slen; i++){
        len_arr[i] = func(s, i);
        if (maxlen < len_arr[i]) {
            maxlen = len_arr[i];
            pos = i;
        }
    }
    for (int i = pos; i < pos+maxlen; i++) printf("%c", s[i]);
    printf("\n");
    return 0;
}
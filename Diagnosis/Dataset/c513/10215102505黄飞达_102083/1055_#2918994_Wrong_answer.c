#include <stdio.h>
#include <string.h>

int used[128] = {0};


int func(char s[], int i){
    for (int j = 0; i+j<strlen(s); j++){
        if (used[s[i+j]]>0) return j;
        else used[s[i+j]]++;
    }
    return strlen(s)-i;
}

int main(){
    char s[10005] = {0};
    gets(s);
    int slen = strlen(s);
    int len_arr[10005] = {0};
    len_arr[0] = func(s, 0);
    int maxlen = len_arr[0], pos = 0;
    for (int i = 1; i < slen; i++){
        len_arr[i] = func(s, i+len_arr[i-1]-1)+len_arr[i-1]-1;
        used[s[i]]--;
        if (maxlen < len_arr[i]) {
            maxlen = len_arr[i];
            pos = i;
        }
    }
    for (int i = pos; i < pos+maxlen; i++) printf("%c", s[i]);
    printf("\n");
    return 0;
}
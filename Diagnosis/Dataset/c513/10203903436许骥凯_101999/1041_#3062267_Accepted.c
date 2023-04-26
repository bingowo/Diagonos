#include<stdio.h>
#include<string.h>

int main(){
    char s[51];
    scanf("%s", s);
    int max_len = 1, len = 1;
    for (int i = 0; i != strlen(s) - 1; ++i){
        if (s[i] != s[i + 1]) ++len;
        else{
            max_len = (len > max_len? len: max_len);
            len = 1;
        }
    }
    max_len = (len > max_len? len: max_len);
    printf("%d\n", max_len);
    return 0;
}